#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(char c);

/**
 * _printf - Our custom printf function
 * @format: The format string
 * @... : The values to format and print
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
		{
			if (format[i + 1] == 'c')
			{
				char c = (char) va_arg(args, int);
				count += print_char(c);
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);
				while (*str)
				{
					count += print_char(*str);
					str++;
				}
			}
			else if (format[i + 1] == '%')
			{
				count += print_char('%');
			}
			i++;
		}
		else
		{
			count += print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

