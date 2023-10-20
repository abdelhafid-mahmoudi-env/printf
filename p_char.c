#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * p_char - writes a char to fd 1
 * @args: variadic arguments to pick the char from
 *
 * Return: 1 on success or -1 on failure
 */

int p_char(va_list *args)
{
	char c;

	c = va_arg(*args, int);
	return (write(1, &c, 1));
}
