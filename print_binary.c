#include "main.h"

/**
 * print_binary - Handle the %b specifier (custom)
 * @args: The va_list with the integer to convert to binary
 * @flag: A flag for special formatting (not used in this example)
 * Return: Number of characters printed
 */
int print_binary(va_list args, int flag)
{
	unsigned int num = va_arg(args, unsigned int);

	(void)flag;

	/* Convert the integer to a binary string or use a custom conversion function */
	char binary_str[33];  /* Assumes a 32-bit integer */
	int i, j;
	for (i = 31, j = 0; i >= 0; i--, j++) {
		binary_str[j] = ((num >> i) & 1) + '0';
	}
	binary_str[j] = '\0';

	return write(1, binary_str, strlen(binary_str));
}

