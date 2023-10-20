#include "main.h"

int _puts(const char *str)
{
    int count = 0;
    while (*str)
    {
        putchar(*str);
        str++;
        count++;
    }
    return count;
}

