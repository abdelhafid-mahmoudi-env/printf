#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function that handles 'c', 's', and '%' conversion specifiers.
 * @format: The format string containing conversion specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int char_count = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            char_count++;
        }
        else if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    char_count++;
                    char character = va_arg(args, int);
                    write(1, &character, 1);
                    break;
                case 's':
                    char *str = va_arg(args, char *);
                    int len = 0;
                    while (str[len] != '\0')
                        len++;
                    char_count += write(1, str, len);
                    break;
                case '%':
                    char_count++;
                    write(1, "%", 1);
                    break;
                default:
                    char_count++;
                    write(1, "%", 1);
                    write(1, &format[i], 1);
            }
        }
    }

    va_end(args);
    return char_count;
}
