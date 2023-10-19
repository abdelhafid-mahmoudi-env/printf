#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Custom printf function */
int _printf(const char *format, ...);

/* Function prototypes for handling different specifiers */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_hex_upper(va_list args);
int print_string_upper(va_list args);
int print_pointer(va_list args);
int print_custom(va_list args);
int print_custom_S(va_list args);
int print_custom_p(va_list args);
int print_custom_r(va_list args);
int print_custom_R(va_list args);

/* Additional functions for formatting and handling special characters */
/* You may need to add more functions as necessary */

#endif /* MAIN_H */
