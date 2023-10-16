#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
void print_char(va_list args);
void print_string(va_list args);
typedef void (*print_func)(va_list args);
#endif /* MAIN_H */

