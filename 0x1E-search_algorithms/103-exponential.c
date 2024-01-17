#include "search_algos.h"

/**
 * binary_search - searches for a value in an array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, mid, left = 0, right = size - 1;

	if (!array)
		return (-1);
	while (left <= right)
	{
		mid = (left + right) / 2;
		printf("Searching in array: ");
		for (i = left; i < right; i++)
		{
			printf("%d, ", array[i]);
		}
		printf("%d\n", array[right]);
		if (array[mid] == value)
			return (mid);
		if (value > array[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

/**
 * exponential_search - searches for a value in an array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t low = 0, high, bound = 1;
	int pos;

	if (!array)
		return (-1);
	if (array[low] == value)
		return (low);
	while (bound < size && array[bound] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
		if (array[bound] == value)
			return (bound);
		bound *= 2;
	}
	low = bound / 2;
	high = (bound < size) ? bound : size - 1;
	printf("Value found between [%ld] and [%ld]\n", low, high);
	pos = binary_search(&array[low], ((high - low) + 1), value);
	if (pos >= 0)
		return (pos + low);
	else
		return (-1);
}
