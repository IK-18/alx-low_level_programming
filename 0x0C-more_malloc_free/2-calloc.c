#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: number of members
 * @size: size of each member
 *
 * Return: nothing
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *arr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	i = 0;
	arr = malloc(nmemb * size);
	while (i <= nmemb)
	{
		if (i < (nmemb * size))
			*((char *)(arr) + i) = 0;
		i++;
	}
	return (arr);
}
