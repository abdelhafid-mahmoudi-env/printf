#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    char buffer[1024];
    int i = 0, j = 0;
    char *str;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    buffer[j++] = (char)va_arg(args, int);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                        buffer[j++] = *(str++);
                    break;
                case '%':
                    buffer[j++] = '%';
                    break;
                case 'p':
                    buffer[j++] = '0';
                    buffer[j++] = 'x';
                    str = convert_address(va_arg(args, void *));
                    while (*str)
                        buffer[j++] = *(str++);
                    break;
                case 'u':
                case 'o':
                case 'x':
                case 'X':
                    str = convert_unsigned(va_arg(args, unsigned int), format[i]);
                    while (*str)
                        buffer[j++] = *(str++);
                    break;
                case 'S':
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                    {
                        if (*str < 32 || *str >= 127)
                        {
                            buffer[j++] = '\\';
                            buffer[j++] = 'x';
                            buffer[j++] = '0' + (*str / 16);
                            buffer[j++] = '0' + (*str % 16);
                        }
                        else
                            buffer[j++] = *(str);
                        str++;
                    }
                    break;
                case 'd':
                case 'i':
                    str = convert_signed(va_arg(args, int));
                    while (*str)
                        buffer[j++] = *(str++);
                    break;
                case 'b':
                    str = convert_binary(va_arg(args, unsigned int));
                    while (*str)
                        buffer[j++] = *(str++);
                    break;
                default:
                    buffer[j++] = '%';
                    buffer[j++] = format[i];
                    break;
            }
        }
        else
            buffer[j++] = format[i];
        i++;
    }

    va_end(args);

    write(1, buffer, j);
    printed_chars += j;

    return printed_chars;
}

/**
 * convert_address - Converts an address to a string.
 * @ptr: The address to convert.
 *
 * Return: The converted string.
 */
char *convert_address(void *ptr)
{
    unsigned long int address = (unsigned long int)ptr;
    char *hex = "0123456789abcdef";
    char buffer[20];
    int i = 0, j = 0;

    if (address == 0)
        return ("0");

    while (address)
    {
        buffer[i++] = hex[address % 16];
        address /= 16;
    }

    buffer[i] = '\0';

    for (j = 0; j < i / 2; j++)
    {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return (buffer);
}

/**
 * convert_unsigned - Converts an unsigned integer to a string.
 * @num: The unsigned integer to convert.
 * @specifier: The conversion specifier ('u', 'o', 'x', or 'X').
 *
 * Return: The converted string.
 */
char *convert_unsigned(unsigned int num, char specifier)
{
    char *str = malloc(20);
    int i = 0;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return (str);
    }

    while (num)
    {
        if (specifier == 'u')
            str[i++] = (num % 10) + '0';
        else if (specifier == 'o')
            str[i++] = (num % 8) + '0';
        else if (specifier == 'x')
            str[i++] = (num % 16 < 10) ? (num % 16) + '0' : (num % 16) - 10 + 'a';
        else if (specifier == 'X')
            str[i++] = (num % 16 < 10) ? (num % 16) + '0' : (num % 16) - 10 + 'A';
        num /= (specifier == 'u') ? 10 : 16;
    }

    str[i] = '\0';

    for (int j = 0; j < i / 2; j++)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    return (str);
}

/**
 * convert_signed - Converts a signed integer to a string.
 * @num: The signed integer to convert.
 *
 * Return: The converted string.
 */
char *convert_signed(int num)
{
    char *str = malloc(20);
    int i = 0;
    int is_negative = 0;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return (str);
    }

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

    while (num)
    {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }

    if (is_negative)
        str[i++] = '-';

    str[i] = '\0';

    for (int j = 0; j < i / 2; j++)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    return (str);
}

/**
 * convert_binary - Converts an unsigned integer to a binary string.
 * @num: The unsigned integer to convert.
 *
 * Return: The converted string.
 */
char *convert_binary(unsigned int num)
{
    char *str = malloc(33);
    int i = 0;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return (str);
    }

    while (num)
    {
        str[i++] = (num % 2) + '0';
        num /= 2;
    }

    str[i] = '\0';

    for (int j = 0; j < i / 2; j++)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    return (str);
}
