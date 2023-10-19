#include "main.h"

/**
 * print_hex - Handle the %x specifier
 * @args: The va_list with the integer to convert to hexadecimal
 * @flag: A flag for special formatting (not used in this example)
 * Return: Number of characters printed
 */
int print_hex(va_list args, int flag)
{
	unsigned int num = va_arg(args, unsigned int);

	(void)flag;

	/* Convert the integer to a lowercase hexadecimal string or use a custom conversion function */
	char hex_str[12];  /* Assumes a 32-bit integer */
	sprintf(hex_str, "%x", num);

	return write(1, hex_str, strlen(hex_str));
}
