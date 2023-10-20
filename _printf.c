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
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{i
				putchar(va_arg(args, int));
				count++;
			}
			else if (*format == 's')
			{
				count += _puts(va_arg(args, char *));
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
