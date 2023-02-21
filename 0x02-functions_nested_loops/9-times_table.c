#include <main.h>

/**
 * times_table - Print the 9 times table, starting with 0
 * Return: 0
 */
int times_table(void)
{
	int a = 0; /* factor */
	int b; /* count  */
	int c; /* computed value */

	while (a < 10)
	{
		b = 0;
		while (c < 10)
		{
			a = b * c;
			if (c > 9)
			{
				_putchar(c / 10 + '0');
				_putchar(c % 10 + '0');
			}
			else
			{
				_putchar(' ');
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
	return (0);
}
