#include "main.h"
#include <stdarg.h>

int print_char(char c);

/**
 * _printf - Our custom printf function
 * @format: The format string
 * @...: The values to format and print
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
		{
			if (format[i + 1] == 'c')
			{
				count += print_char(va_arg(args, int));
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);
				int j = 0;

				while (str && str[j])
				{
					count += print_char(str[j]);
					j++;
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

