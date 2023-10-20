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

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				count += _puts(str);
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

