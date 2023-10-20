#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>

int _printf(const char *format, ...);
int p_char(va_list *args);
int p_integer(va_list *args);
int p_str(va_list *args);
char *stringify(int number);

#endif /* _MAIN_H_ */
