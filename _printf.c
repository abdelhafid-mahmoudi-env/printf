#include "main.h"
#include <unistd.h>

/**
* write_char - Writes a character to stdout.
* @c: The character.
* @count: The count of characters.
*/
void write_char(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}

/**
* write_string - Writes a string to stdout.
* @str: The string.
* @count: The count of characters.
*/
void write_string(char *str, int *count)
{
    int len = 0;

    while (str[len])
    {
   	 write(1, &str[len], 1);
   	 len++;
    }
    (*count) += len;
}

/**
* _printf - Our custom printf function.
* @format: The format string.
* @...: The values to format and print.
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    va_start(args, format);

    while (format && format[i])
    {
   	 if (format[i] == '%' &&
   		 (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
   	 {
   		 if (format[i + 1] == 'c')
   			 write_char(va_arg(args, int), &count);
   		 else if (format[i + 1] == 's')
   			 write_string(va_arg(args, char *), &count);
   		 else if (format[i + 1] == '%')
   			 write_char('%', &count);
   		 i++;
   	 }
   	 else
   	 {
   		 write_char(format[i], &count);
   	 }
   	 i++;
    }
    va_end(args);
    return (count);
}

