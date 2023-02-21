#include "main.h"

/**
 * main - prints alphabet
 *
 * Return: 0
 */
int main(void)
{
	char c = 'a';
	int i;

	for (i = 1; i <= 10; i++)
	{
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
	}
	_putchar('\n');
	return (0);
}
