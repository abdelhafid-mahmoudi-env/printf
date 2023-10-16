#include "main.h"

/**
 * write_number - Converts integer to character and writes to stdout.
 * @n: The integer.
 */
void write_number(int n)
{
    char c;

    c = n + '0';
    write(1, &c, 1);
}

/**
 * print_int - Prints an integer.
 * @args: A va_list pointing to the integer to print.
 * Return: The number of characters printed.
 */
int print_int(va_list args)
{
    int n, num, last_digit, expo, count = 0;

    n = va_arg(args, int);
    num = n;
    expo = 1;
    if (n < 0)
    {
   	 n *= -1;
   	 num *= -1;
   	 write(1, "-", 1);
   	 count++;
    }
    while (num / 10)
    {
   	 num /= 10;
   	 expo *= 10;
    }
    while (expo)
    {
   	 last_digit = n / expo;
   	 n %= expo;
   	 write_number(last_digit);
   	 count++;
   	 expo /= 10;
    }
    return (count);
}
