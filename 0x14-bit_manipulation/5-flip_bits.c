#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another
 * @n: number to flip
 * @m: number to verify
 *
 * Return: number of flips
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int x, change = 0;
	unsigned long int y = sizeof(unsigned long int) * 8;

	for (x = 0; x < y; x++)
	{
		if ((m & 1) != (n & 1))
			change++;
		n = n >> 1;
		m = m >> 1;
	}
	return (change);
}

