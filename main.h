#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
* struct convert - defines a structure for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/
typedef struct convert
{
	char sym;
	int (*f)(va_list);
} cf_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_character(va_list arg);
int print_string(va_list arg);
int print_modulo(va_list arg); /* Vous pouvez également passer void au lieu de va_list si vous n'utilisez pas arg */

#endif /* MAIN_H */

