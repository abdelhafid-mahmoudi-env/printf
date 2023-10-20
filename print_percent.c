#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_percent - Print a percent sign
 * @args: The va_list (not used)
 *
 * Return: Number of characters printed (always 1)
 */
int print_percent(va_list args)
{
    (void)args; // Unused parameter
    write(1, "%", 1);
    return 1;
}

