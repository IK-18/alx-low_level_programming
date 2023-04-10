#include "main.h"

void print_binary(unsigned long int n)
{
	int i;
	unsigned long int value;
	bool digits = false;

	for (i = 63; i >= 0; i--)
	{
		value = n >> i;
		if (value & 1)
		{
			_putchar('1');
			digits = true;
		}
		else if (digits)
			_putchar('0');
	}
	if (!digits)
		_putchar('0');
}
