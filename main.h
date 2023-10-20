#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(va_list args);
int print_char(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */

