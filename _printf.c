#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i;
	char *str;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else if (format[i + 1])
		{
			i++;
			switch (format[i])
			{
			case 'c':
				_putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				print_string(str, &count);
				break;
			default:
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
	}

	va_end(args);
	return (count);
}

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * print_string - Prints a string character by character
 * @str: The string to print
 * @count: Pointer to the character count
 */
void print_string(char *str, int *count)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
		(*count)++;
	}
}

