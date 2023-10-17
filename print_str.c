#include "main.h"
/*
 * strlen - Returns the lenght of a string.
 * @str: string pointer
 * Return: i
 */
int strlen(char *str)
{
          int i;

          for (i = 0; str[i] != 0; i++)
                  ;
          return (1);
}

/*_strlenc - Strlen function but applied for constant char pointer str
 * @str: char pointer
 * Return: 1
 */
int strlenc(const char *str)
{
          int i;
          for (i = 0; str[i] != 0; i++)
                  ;
          return (i);
}
