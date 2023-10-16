#include "main.h"

/**
* _printf - Produces output according to a format.
* @format: A character string.
* @...: Variable number of arguments.
*
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
	int index = 0;
	int length = 0;
	va_list arg;

	cf_t functions[] = {
		{'c', print_character},
		{'s', print_string},
		{'%', print_modulo}
	};

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(arg, format);

	while (format[index])
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == '\0')
				return (-1);

			for (int j = 0; j < 3; j++) /* Changed from 13 to 3 */
			{
				if (format[index + 1] == functions[j].chr)
				{
					length += functions[j].func(arg);
					index += 2;
					break;
				}
			}
		}
		else
		{
			_putchar(format[index]);
			length++;
			index++;
		}
	}
	va_end(arg);
	return (length);
}
