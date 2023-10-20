#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * reversing - allowing to reverse
 * @s: string to reverse
 *
 * Return: nothing
 */

void reversing(char *s)
{
	int start, end;
	char temp;

	end = strlen(s) - 1;
	for (start = 0; start < end; start++, end--)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
	}
}
/**
 * stringify - this function allows to stringify the number
 * @number: number to reverse
 *
 * Return: string
 */

char *stringify(int number)
{
	char *s;
	int i = 0;
	long n = number;

	s = malloc(12);
	if (!s)
		return (NULL);
	if (number == 0)
	{
		*s = '0';
		*(s + 1) = '\0';
		return (s);
	}
	if (number < 0)
		n = -n;

	while (n != 0)
	{
		s[i++] = '0' + n % 10;
		n /= 10;
	}
	if (number < 0)
		s[i++] = '-';
	s[i] = '\0';
	reversing(s);
	return (s);
}
