#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: lowest number
 * @max: highest number
 *
 * Return: array
 */

int *array_range(int min, int max)
{
	int i, j, *arr;

	i = min;
	j = 0;
	if (min > max)
		return (NULL);
	arr = malloc(sizeof(int) * (max - min) + 1);
	if (arr == NULL)
		return (NULL);
	while (i >= min && i <= max)
	{
		arr[j] = i;
		i++;
		j++;
	}
	return (arr);
}
