#include "main.h"

/**
 * print_pointer - Handle the %p specifier (print pointer address)
 * @args: The va_list with the pointer to print
 * @flag: A flag for special formatting (not used in this example)
 * Return: Number of characters printed
 */
int print_pointer(va_list args, int flag)
{
	void *ptr = va_arg(args, void *);

	(void)flag;

	/* Convert the pointer address to a hexadecimal string */
	unsigned long int address = (unsigned long int)ptr;
	char hex_str[20]; /* Assumes a 64-bit address */
	sprintf(hex_str, "0x%lx", address);

	return write(1, hex_str, strlen(hex_str));
}

