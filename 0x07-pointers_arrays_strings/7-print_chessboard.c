#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: board
 *
 * Return: nothing
 */

void print_chessboard(char (*a)[8])
{
	int r, c, i, j;

	r = sizeof(a);
	c = sizeof(a[0]);
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			_putchar(a[i][j]);
		_putchar('\n');
	}
}
