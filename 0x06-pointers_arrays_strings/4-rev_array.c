#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array
 * @n: number of elements to swap
 * Return: nothing
 */

void reverse_array(int *a, int n)
{
	int i, j, hold;

	i = n - 1;
	j = 0;
	while (j < n / 2)
	{
		hold = a[j];
		a[j] = a[i];
		a[i] = hold;
		i--;
		j++;
	}
}
