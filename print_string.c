#include "main.h"

/**
 * print_string - Print a string to stdout.
 * @str: The string to print.
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

