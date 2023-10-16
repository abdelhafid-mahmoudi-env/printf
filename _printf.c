/* Include the header file */
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
	unsigned int i = 0, count = 0;
	va_list args;
	print_func funcs[] = {print_char, print_string};

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'))
		{
			if (format[i + 1] == 'c')
				funcs[0](args);
			else if (format[i + 1] == 's')
				funcs[1](args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
		}
		count++;
		i++;
	}

	va_end(args);
	return (count);
}

