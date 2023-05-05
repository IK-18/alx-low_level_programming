#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number
 * @index: index of bit
 *
 * Return: value of bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int number;

	number = n >> index;
	if (index > 32)
		return (-1);
	return (number & 1);
}

