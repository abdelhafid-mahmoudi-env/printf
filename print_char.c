#include "main.h"
#include <unistd.h>

/**
 * print_char - Prints a character to stdout
 * @c: The character to print
 *
 * Return: The number of characters printed
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

