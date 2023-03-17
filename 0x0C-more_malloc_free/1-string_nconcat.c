#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes
 *
 * Return: new string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;
	if (n >= len2)
		str = malloc(len1 + len2 + 1);
	else
		str = malloc(len1 + n + 1);
	if (str == NULL)
		return (NULL);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	if (n >= len2)
	{
		while (j < len2)
		{
			str[i] = s2[j];
			i++;
			j++;
		}
	}
	else
	{
		while (j < n)
		{
			str[i] = s2[j];
			i++;
			j++;
		}
	}
	return (str);
}
