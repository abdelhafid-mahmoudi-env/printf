#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * print_int - Print an integer to stdout
 * @args: A va_list containing the integer to print
 *
 * Return: The number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    int count = 0;
    char buffer[20];

    count = snprintf(buffer, sizeof(buffer), "%d", n);

    if (count < 0)
        return (0);

    write(1, buffer, count);

    return (count);
}

