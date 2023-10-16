#include "main.h"
#include <unistd.h>

/**
 * print_char - prints a character
 * @c: character to print
 * Return: 1 (number of characters printed)
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

