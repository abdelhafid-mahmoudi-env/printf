#include "main.h"

/**
 * print_char - Handle the %c specifier
 * @args: The va_list with the character to print
 * @flag: A flag for special formatting (not used in this example)
 * Return: Number of characters printed
 */
int print_char(va_list args, int flag)
{
	char c = va_arg(args, int);

	(void)flag;
	return write(1, &c, 1);
}

