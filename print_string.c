#include "main.h"

/**
 * print_string - Print a string
 * @args: The va_list containing the string
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    while (*str)
    {
        _putchar(*str);
        str++;
        count++;
    }
    return count;
}

