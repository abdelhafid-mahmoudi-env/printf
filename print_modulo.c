#include "main.h"
#include <stdarg.h>

/**
* print_modulo - Writes a percent symbol to stdout
* @arg: argument list
* Return: number of characters written
*/
int print_modulo(va_list arg __attribute__((unused)))
{
	return (_putchar('%'));
}

