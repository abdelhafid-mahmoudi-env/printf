#include "main.h"

/**
 * print_unsigned - Handle the %u specifier
 * @args: The va_list with the unsigned integer to print
 * @flag: A flag for special formatting (not used in this example)
 * Return: Number of characters printed
 */
int print_unsigned(va_list args, int flag)
{
	unsigned int num = va_arg(args, unsigned int);

	(void)flag;

	/* Convert the unsigned integer to a string or use a custom conversion function */
	char num_str[12];  /* Assumes a 32-bit unsigned integer */
	sprintf(num_str, "%u", num);

	return write(1, num_str, strlen(num_str));
}

