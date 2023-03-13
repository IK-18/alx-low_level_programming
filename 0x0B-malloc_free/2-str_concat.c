#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	int i, j, len;
	char *string;

	i = 0;
	j = 0;
	len = 0;
	if (s1 == NULL)
	{
		s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = '\0';
	}
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	len = i + j;
	string = (char *) malloc(sizeof(char) * len + 1);
	i = j = 0;
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	return (string);
}
