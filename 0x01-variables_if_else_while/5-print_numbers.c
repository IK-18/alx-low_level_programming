#include <stdio.h>
/**
 * main - prints all single digits less than 10
 * Return: 0
 */

int main(void)
{
	int c = 0;

	while (c < 10)
	{
		printf("%d", c);
		c++;
	}
	putchar('\n');
	return (0);
}
