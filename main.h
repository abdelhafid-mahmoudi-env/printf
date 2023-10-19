#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/* Function prototypes for your custom conversion specifiers */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_pointer(va_list args);
int print_custom_string(va_list args);
int print_reversed_string(va_list args);
int print_rot13_string(va_list args);

#endif
