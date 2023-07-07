#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number
 * @index: index of bit
 *
 * Return: value at index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i = 0;

	if (n == 0 && index < 64)
		return (0);

	while (i <= 63)
	{
		if (index == i)
			return (n & 1);
		n >>= 1;
		i++;
	}

	return (-1);
}
