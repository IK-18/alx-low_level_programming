#include <math.h>
#include "search_algos.h"

/**
 * jump_search - searches for a value in an array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i = 0, step;

	if (!array)
		return (-1);
	step = sqrt(size);
	while (array[i] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		if (array[step] >= value || step >= size)
			break;
		i = step;
		step += sqrt(size);
	}
	printf("Value found between indexes [%ld] and [%ld]\n", i, step);
	while (i < size)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}
	if (array[i] == value)
		return (i);
	return (-1);
}
