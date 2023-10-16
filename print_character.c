#include "main.h"
#include <stdarg.h>

/**
* print_character - Writes a character to stdout
* @arg: argument list
* Return: number of characters written
*/
int print_character(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	return (_putchar(c));
}
