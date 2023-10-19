#include "main.h"

/**
 * print_int - Handle the %d and %i specifiers
 * @args: The va_list with the integer to print
 * @flag: A flag for special formatting (not used in this example)
 * Return: Number of characters printed
 */
int print_int(va_list args, int flag)
{
	int num = va_arg(args, int);

	(void)flag;

	/* Convert the integer to a string or use a custom conversion function */
	char num_str[12];  /* Assumes a 32-bit integer */
	sprintf(num_str, "%d", num);

	return write(1, num_str, strlen(num_str));
}

