#include "search_algos.h"

/**
 * advanced_binary - searches for a value in an array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid, left = 0, right = size - 1;

	if (!array)
		return (-1);
	while (left <= right)
	{
		mid = (left == 0) ? (left + right + 1) / 2 : (left + right) / 2;
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[right]);
		if (array[mid] == value)
		{
			if (mid == left || array[mid - 1] != value)
				return (mid);
			right = mid - 1;
		}
		else if (value > array[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
