#include "main.h"

/**
 * print_octal - Handle the %o specifier
 * @args: The va_list with the integer to convert to octal
 * @flag: A flag for special formatting (not used in this example)
 * Return: Number of characters printed
 */
int print_octal(va_list args, int flag)
{
	unsigned int num = va_arg(args, unsigned int);

	(void)flag;

	/* Convert the integer to an octal string or use a custom conversion function */
	char octal_str[12];  /* Assumes a 32-bit integer */
	sprintf(octal_str, "%o", num);

	return write(1, octal_str, strlen(octal_str));
}

