#include "main.h"

/**
 * print_percent - Handle the %% specifier
 * @args: The va_list (not used)
 * @flag: A flag for special formatting (not used)
 * Return: Number of characters printed
 */
int print_percent(va_list args, int flag)
{
	(void)args;
	(void)flag;
	return write(1, "%", 1);
}

