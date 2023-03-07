#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - searhces a string for any of a set of bytes
 * @s: string to search through
 * @accept: string to be found
 *
 * Return: pointer
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}
		s++;
	}
	return (NULL);
}
