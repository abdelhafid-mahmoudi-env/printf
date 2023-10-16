/* Include the header file */
#include "main.h"
#include <unistd.h>

/**
 * print_char - Prints a character
 * @args: List of arguments
 */
void print_char(va_list args)
{
	char c = va_arg(args, int);
	write(1, &c, 1);
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

