#include <unistd.h>
#include <stdarg.h>
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
    if (str == NULL)
        str = "(null)";
    while (*str)
    {
        write(1, str, 1);
        str++;
        count++;
    }
    return count;
}

