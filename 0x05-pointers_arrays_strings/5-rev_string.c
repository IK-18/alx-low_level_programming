#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string
 * Return: reversed string
 */

void rev_string(char *s)
{
	char l;
	int len, i, j;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	i = len - 1;
	j = 0;
	while (i >= len / 2)
	{
		l = s[j];
		s[j] = s[i];
		s[i] = l;
		j++;
		i--;
	}
}
