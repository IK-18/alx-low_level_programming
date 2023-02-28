#include "main.h"

/**
 * print_rev - print a string in reverse
 * @s: string
 * Return: reversed string
 */

void print_rev(char *s)
{
	int len, i;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	i = len - 1;
	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}
