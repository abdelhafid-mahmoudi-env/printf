#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Prototype for the main _printf function */
int _printf(const char *format, ...);

/* Prototypes for functions to handle format specifiers */
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);

#endif /* MAIN_H */

