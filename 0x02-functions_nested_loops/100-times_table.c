#include "main.h"

/**
 * print_times_table - Print the 9 times table, starting with 0
 * @n: int type number
 * Return: 0
 */

void print_times_table(int n)
{
	int a = 0; /* factor */
	int b; /* count  */
	int c; /* computed value */

	if (n > 15 || n < 0)
		return;

	while (a <= n)
	{
		b = 0;
		while (b < n)
		{
			c = a * b;
			if (c > 99)
			{
				_putchar(c / 100 + '0');
				_putchar((c / 10 % 10) + '0');
				_putchar(c % 10 + '0');
			}
			if (c > 9)
			{
				_putchar(c / 10 + '0');
				_putchar(c % 10 + '0');
			}
			else if (b != 0)
			{
				_putchar(' ');
				_putchar(c + '0');
			}
			else
			{
				_putchar(c + '0');
			}

			if (b != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
			b++;
		}
		_putchar('\n');
		a++;
	}
}
