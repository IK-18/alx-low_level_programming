#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: binary number to change
 *
 * Return: unsigned int
 */

unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int num = 0;

	if (!b)
		return (0);
	for (x = 0; b[x]; x++)
	{
		if (b[x] < '0' || b[x] > '1')
			return (0);
		num = 2 * num + (b[x] - '0');
	}
	return (num);
}

