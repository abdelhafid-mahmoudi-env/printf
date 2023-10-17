#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int _putchar(char c);
int _printf(const char *format, ...);
int printf_str(va_list args, int printed);
int printf_char(va_list args, int printed);
int _percent(char *format, va_list list);
int selector(const char *format, va_list args, int printed);

#endif
