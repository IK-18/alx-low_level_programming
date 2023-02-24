#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: size of triangle
 * Return: triangle
 */

void print_triangle(int size)
{
	int a, b, c;

	for (c = 0; c < size; c++)
	{
		for (a = 1; a < size - c; a++)
		{
			_putchar(32);
		}
		for (b = 0; b <= c; b++)
		{
			_putchar(35);
		}
		_putchar('\n');
	}
}
