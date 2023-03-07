#include "main.h"

/**
 * _strpbrk - searhces a string for any of a set of bytes
 * @s: string to search through
 * @accept: string to be found
 *
 * Return: pointer
 */

char *_strpbrk(char *s, char *accept)
{
	int i, j;

	while (*s != '\0')
	{
		i = *s++;
		j = 0;
		while (accept[j] != '\0')
		{
			if (accept[j] == i)
				return (s - 1);
			j++;
		}
		s++;
	}
	return (0);
}
