#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_array - creates an array
 * @size: size of array
 * @c: character that fills array
 *
 * Return: pointer to array
 */

char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
		return (NULL);

	arr = (char *) malloc(sizeof(char) * size);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		arr[i] = c;
	}
	return (arr);
}
