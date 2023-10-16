#include "main.h"
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
	int i = 0, count = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
		{
			if (format[i + 1] == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);
				int len = 0;

				while (str[len])
				{
					write(1, &str[len], 1);
					len++;
				}
				count += len;
			}
			else if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				count++;
			}
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}


