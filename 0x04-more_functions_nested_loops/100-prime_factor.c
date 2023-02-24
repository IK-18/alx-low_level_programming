#include <stdio.h>
#include "main.h"

/**
 * main - prints the largest prime factor
 * Return: the largest prime number
 */

int main(void)
{
	unsigned long int i, j, n, max;

	n = 612852475143;
	for (i = 2; i <= n; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (!(i % j == 0))
				max = i;
		}
	}
	printf("%lu\n", max);
	return (0);
}
