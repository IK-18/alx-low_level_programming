#include "search_algos.h"

/**
 * interpolation_search - searches for a value in an array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;
	int index = 0;

	if (!array)
		return (-1);
	low = 0;
	high = size - 1;
	while (low <= high && value >= array[low] && value <= array[high])
	{
		pos = low + (((double)(high - low) /
			      (array[high] - array[low])) * (value - array[low]));
		index = array[pos];
		printf("Value checked array[%ld] = [%d]\n", pos, index);
		if (index == value)
			return (pos);
		if (index < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
	printf("Value checked array[%ld] is out of range\n", pos);
	return (-1);
}
