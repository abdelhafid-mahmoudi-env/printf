#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/* Forward declaration */
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
		if (format[i] == '%' && (format[i + 1] == 'c' ||
					 format[i + 1] == 's' ||
					 format[i + 1] == '%' ||
					 format[i + 1] == 'r')) /* Added 'r' */
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
		
			else if (format[i + 1] == 'r') /* Handle 'r' */
{
    char *str = va_arg(args, char *);
    int j = 0;

    if (str != NULL)
    {
        while (str[j])
        {
            count += print_char(str[j]);
            j++;
        }
    }
    else
    {
        count += print_char('N'); /* Handle NULL string */
        count += print_char('U');
        count += print_char('L');
        count += print_char('L');
    }
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

