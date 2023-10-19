#include "main.h"

/**
 * print_string - Handle the %s specifier
 * @args: The va_list with the string to print
 * @flag: A flag for special formatting (not used in this example)
 * Return: Number of characters printed
 */
int print_string(va_list args, int flag)
{
	char *str = va_arg(args, char *);

	(void)flag;

	if (str == NULL)
		str = "(null)";

	int len = 0;
	while (str[len] != '\0')
		len++;

	return write(1, str, len);
}
