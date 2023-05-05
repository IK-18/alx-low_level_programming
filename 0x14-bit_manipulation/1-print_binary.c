#include "main.h"

/**
 * print_binary -  prints the binary representation of a number
 * @n: number
 *
 * Return: nothing
 */

void print_binary(unsigned long int n)
{
	int x;
	unsigned long int digit;
	bool valid = false;

	for (x = 64; x >= 0; x--)
	{
		digit = n >> x;
		if (digit & 1)
		{
			_putchar('1');
			valid = true;
		}
		else if (valid)
			_putchar('0');
	}
	if (!valid)
		_putchar('0');
}

