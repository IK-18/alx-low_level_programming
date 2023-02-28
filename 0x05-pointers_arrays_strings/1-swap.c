#include "main.h"

/**
 * swap_int - swaps values of pointers
 * @a: first integer to be swapped
 * @b: other integer
 * Return: Always 0
 */

void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
