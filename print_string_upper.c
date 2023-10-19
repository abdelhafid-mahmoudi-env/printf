#include "main.h"

/**
 * print_string_upper - Handle the %S specifier (print uppercase string)
 * @args: The va_list with the string to print
 * @flag: A flag for special formatting (not used in this example)
 * Return: Number of characters printed
 */
int print_string_upper(va_list args, int flag)
{
	char *str = va_arg(args, char *);

	(void)flag;

	if (str == NULL)
		str = "(null)";

	int len = 0;
	while (str[len] != '\0')
		len++;

	for (int i = 0; i < len; i++) {
		if (str[i] < 32 || str[i] >= 127) {
			/* Handle non-printable characters */
			/* Print in the format \xXX where XX is the ASCII value in hexadecimal */
			char hex[5];
			snprintf(hex, 5, "\\x%02X", (unsigned char)str[i]);
			write(1, hex, 4);
		} else {
			/* Print printable characters as is */
			write(1, &str[i], 1);
		}
	}

	return len;
}

