#include <stdio.h>
/**
 * main - prints all numbers of base 16
 * Return: 0
 */

int main(void)
{
	char c = 'a';
	int i = 0;

	while (i < 10)
	{
		putchar(i + '0');
		i++;
	}
	while (c < 'g')
	{
		putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}
