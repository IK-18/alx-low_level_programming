#include "main.h"

/**
 * print_alphabet_x10 - prints alphabet
 *
 * Return: 0
 */
void print_alphabet_x10(void)
{
	char c = 'a';
	int i = 1;

	while (i <= 10)
	{
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		i++;
	}
	_putchar('\n');
}
