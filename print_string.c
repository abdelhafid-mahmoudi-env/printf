#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_string - Print a string to stdout
 * @args: A va_list containing the string to print
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        write(1, str, 1);
        str++;
        count++;
    }
    return (count);
}

