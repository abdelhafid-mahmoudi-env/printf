#include "main.h"
#include <stdio.h>  // For NULL
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			i++;
			while (format[i] == ' ')
				i++;
			if (format[i] == '%')
				count += write(1, &format[i], 1);
			else
			{
				int j = 0, flag = 0;
				specifier_t specifiers[] = {
					{'c', print_char},
					{'s', print_string},
					{'%', print_percent},
					{'d', print_int},
					{'i', print_int},
					{'b', print_binary},
					{'u', print_unsigned},
					{'o', print_octal},
					{'x', print_hex},
					{'X', print_hex_upper},
					{'S', print_string_upper},
					{'p', print_pointer},
					{'r', print_custom_r},
					{'R', print_custom_R},
					{0, NULL}
				};

				while (specifiers[j].specifier)
				{
					if (format[i] == specifiers[j].specifier)
					{
						count += specifiers[j].function(args, flag);
						break;
					}
					j++;
				}
				if (!specifiers[j].specifier)
				{
					count += write(1, &format[i - 1], 1);
					count += write(1, &format[i], 1);
				}
			}
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

