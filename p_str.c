#include "main.h"
#include <unistd.h>
#include <string.h>
/**
 * p_str - writes a string to fd 1 or returns -1
 * @args: variadic list to pick the string from
 *
 * Return: strlen or -1
 */

int p_str(va_list *args)
{
	char *s;

	s = va_arg(*args, char *);

	if (!s)
		s = "(null)";
	return (write(1, s, strlen(s)));
}
