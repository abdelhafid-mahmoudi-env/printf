#include "main.h"
#include <stdarg.h>

/**
* print_string - Writes a string to stdout
* @arg: argument list
* Return: number of characters written
*/
int print_string(va_list arg)
{
	int i;
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}
