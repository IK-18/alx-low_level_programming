#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees up the grid
 * @grid: grid
 * @height: height of grid
 *
 * Return: nothing
 */

void free_grid(int **grid, int height)
{
	int i;

	i = 0;
	if (grid == NULL)
		return;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
}
