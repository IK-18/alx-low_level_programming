#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a new string
 * @str: string to be put into memory
 *
 * Return: pointer
 */

char *_strdup(char *str)
{
	int i, len;
	char *s;

	i = 0;
	len = 0;
	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	s = (char *) malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}
