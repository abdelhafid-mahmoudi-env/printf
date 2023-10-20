#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variadic arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            format++;
            if (*format == 'c')
                count += print_char(args);
            else if (*format == 's')
                count += print_string(args);
            else if (*format == '%')
                count += print_percent(args);
        }
        format++;
    }
    va_end(args);
    return count;
}

