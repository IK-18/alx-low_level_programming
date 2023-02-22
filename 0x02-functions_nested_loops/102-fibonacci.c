#include <stdio.h>

/**
 * main - main block
 * Description: Print the first 50 numbers of the Fibonacci sequence.
 * Return: 0
 */
int main(void)
{
	long int a = 1, b = 1, c;
	int count = 1;

	while (count <= 50)
	{
		if (count != 50)
			printf("%lu, ", b);
		else
			printf("%lu\n", b);
		c = b + a;
		a = b;
		b = c;
		count++;
	}
	return (0);
}
