#include "main.h"

/**
 * print_alphabet_x10 - prints alphabet
 *
 * Return: 0
 */
void print_alphabet_x10(void)
{
	int i = 1;

	while (i <= 10)
	{
		char c = 'a';

		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		i++;
	}
	_putchar('\n');
}
