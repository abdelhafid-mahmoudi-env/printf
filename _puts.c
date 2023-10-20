#include "main.h"

/**
* _puts - Prints a string to stdout.
* @str: The string to be printed.
* Return: None (void).
*/
int _puts(const char *str)
{
	int count = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}
