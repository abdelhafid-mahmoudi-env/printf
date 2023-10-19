#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int char_count = 0;

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            char_count++;
        }
        else if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++; // Move past the '%'
            switch (format[i])
            {
                case 'c':
                    char_count += putchar(va_arg(args, int));
                    break;
                case 's':
                    char *str = va_arg(args, char *);
                    if (str != NULL)
                    {
                        char_count += printf("%s", str);
                    }
                    else
                    {
                        char_count += printf("(null)");
                    }
                    break;
                case '%':
                    char_count += putchar('%');
                    break;
                default:
                    char_count += putchar('%'); // Print the '%' itself
                    char_count += putchar(format[i]);
            }
        }
    }

    va_end(args);
    return char_count;
}
