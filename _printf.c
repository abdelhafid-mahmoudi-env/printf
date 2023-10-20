#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...) {
  int count = 0;
  va_list args;

  va_start(args, format);
  while (*format != '\0') {
    if (*format == '%') {
      format++;
      switch (*format) {
        case 'c':
          count += putchar((char) va_arg(args, int));
          break;
        case 's':
          count += puts(va_arg(args, char *));
          break;
        case '%':
          count += putchar('%');
          break;
      }
      format++;
    } else {
      count += putchar(*format);
      format++;
    }
  }

  va_end(args);
  return count;
}

