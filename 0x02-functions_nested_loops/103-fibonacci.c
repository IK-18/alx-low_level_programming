#include <stdio.h>

/**
 * main - main block
 * Description: Print the first 50 numbers of the Fibonacci sequence.
 * Return: 0
 */
int main(void)
{
	long int a = 1, b = 1, c, total = 0;

	while (b < 4000000)
	{
		if (b % 2 == 0)
			total += b;
		c = b + a;
		a = b;
		b = c;
	}
	printf("%lu\n", total);
	return (0);
}
