#include "main.h"
#include <stdarg.h>

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * @...: The values to format and print.
 * Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
	unsigned int i = 0, j = 0;
	va_list args;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
		{
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(args, int));
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);
				while (str && str[j])
				{
					_putchar(str[j]);
					j++;
				}
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (i);
}

