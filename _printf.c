#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function that prints formatted output.
 * @format: The format string.
 * @...: Variable number of arguments.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *str;
	int len = 0;
	char percent = '%';

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				len = 0;
				while(str[len])
					len++;
				write(1, str, len);
				count += len;
			}
			else if (*format == '%')
			{
				percent = '%';
				write(1, &percent, 1);
				count++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

