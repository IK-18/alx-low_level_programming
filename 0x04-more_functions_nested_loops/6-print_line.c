#include "main.h"

/**
 * print_line - prints a line in the terminal
 * @n: length of the line
 * Return: the line
 */

void print_line(int n)
{
	int a = 0, j;

	while (a < n)
	{
		j = 95;
		_putchar(j);
		a++;
	}
	_putchar('\n');
}
