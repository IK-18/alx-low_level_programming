#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals of
 * a square matrix of integers
 * @a: array
 * @size: size
 *
 * Return: nothing
 */

void print_diagsums(int *a, int size)
{
	int i, hold1, hold2;

	hold1 = 0;
	hold2 = 0;
	for (i = 0; i < size; i++)
	{
		hold1 += a[(size * i) + i];
		hold2 += a[(size * (i + 1)) - (i + 1)];
	}
	printf("%d, %d\n", hold1, hold2);
}
