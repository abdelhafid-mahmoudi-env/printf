#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * pluck - handles char
 * @args: variadic arguments
 * @format: the initial string to extract specifiers from
 *
 * Return: int
 */

int pluck(const char **format, va_list *args)
{
	int c;

	switch (*(++(*format)))
	{
		case 'c':
			c = p_char(args);
			break;
		case 's':
			c = p_str(args);
			break;
		case '%':
			c = write(1, "%", 1);
			break;
		case 'i':
		case 'd':
			c = p_integer(args);
			break;
		case ' ':
			c = -1;
			break;
		case '\0':
			c = -1;
			break;
		default:
			--(*format);
			c = write(1, *format, 1);
			break;
	}
	return (c);
}

/**
 * _printf - mimics std printf
 * @format: format specifying string
 *
 * Return: number of chars printed or -1 on failure
 */

int _printf(const char *format, ...)
{
	int c, sum = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			c = pluck(&format, &args);
			if (c == -1)
				return (c);
			sum += c;
			format++;
		}
		else
		{
			c = write(1, format, 1);
			if (c == -1)
				return (c);
			sum++;
			format++;
		}
	}
	va_end(args);
	return (sum);
}
