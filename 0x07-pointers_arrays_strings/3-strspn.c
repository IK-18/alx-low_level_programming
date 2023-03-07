#include "main.h"

/**
 * _strspn - gets the length of a prefix of string
 * @s: string
 * @accept: substring
 *
 * Return: number of bytes
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, j, len, flag;

	i = 0;
	for (len = 0; s[len] != '\0'; len++)
	{
		flag = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[len] == accept[j])
			{
				i++;
				flag = 1;
			}
		}
		if (flag == 0)
			return (i);
	}
	return (0);
}
