#include "main.h"

/**
 * print_char - Print a character
 * @args: The va_list containing the character
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    _putchar(c);
    return 1;
}

