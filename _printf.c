#include "main.h"

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * @...: The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    unsigned int i = 0;

    va_start(args, format);

    while (format && format[i])
    {
   	 if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == 'd'))
   	 {
   		 if (format[i + 1] == 'c')
   			 count += print_char(va_arg(args, int));
   		 else if (format[i + 1] == 's')
   			 count += print_string(va_arg(args, char *));
   		 else if (format[i + 1] == 'd')
   			 count += print_int(va_arg(args, int));
   		 i++;
   	 }
   	 else
   	 {
   		 write(1, &format[i], 1);
   		 count++;
   	 }
   	 i++;
    }

    va_end(args);

    return (count);
}

