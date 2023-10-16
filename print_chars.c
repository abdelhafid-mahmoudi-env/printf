#include "main.h"

/**
 * print_char - Writes a character to stdout
 * @args: A va_list pointing to the character to write
 * Return: The number of characters printed.
 */
int print_char(va_list args)
{
    char c;

    c = va_arg(args, int);
    write(1, &c, 1);
    return (1);
}

/**
 * print_string - Writes a string to stdout
 * @args: A va_list pointing to the string to write
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
    char *str;
    int i;
    int count = 0;

    str = va_arg(args, char *);
    if (str == NULL)
   	 str = "(null)";
    for (i = 0; str[i]; i++)
    {
   	 write(1, &str[i], 1);
   	 count++;
    }
    return (count);
}
