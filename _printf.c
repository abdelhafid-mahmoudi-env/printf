#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * @...: The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int i = 0, count = 0;
    va_list args;

    va_start(args, format);
    while (format && format[i])
    {
   	 if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
   	 {
   		 i++;
   		 if (format[i] == 'c')
   		 {
   			 char c = va_arg(args, int); // va_arg for char promotes to int
   			 count += write(1, &c, sizeof(char));
   		 }
   		 else if (format[i] == 's')
   		 {
   			 char *s = va_arg(args, char *);
   			 while (*s)
   			 {
   				 count += write(1, s, 1);
   				 s++;
   			 }
   		 }
   		 else if (format[i] == '%')
   			 count += write(1, "%", 1);
   	 }
   	 else
   		 count += write(1, &format[i], 1);
   	 i++;
    }
    va_end(args);
    return (count);
}
