#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Our custom printf function.
* @format: The format string.
* @...: The values to format and print.
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0, count = 0;
	cf_t types[] = {
		{'c', print_character},
		{'s', print_string},
		{'%', print_modulo},
		{0, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
		{
			count += types[format[i + 1] - 'c'].f(args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
