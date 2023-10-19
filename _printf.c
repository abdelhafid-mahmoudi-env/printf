#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Print output according to a format
 * @format: A format string containing zero or more directives
 * @...: Variable number of arguments based on the format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;

            if (*format == 'c')
                count += print_char(args);
            else if (*format == 's')
                count += print_string(args);
            else if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                write(1, "%", 1);
                count++;
                write(1, format, 1);
                count++;
            }
        }
        format++;
    }

    va_end(args);
    return (count);
}

