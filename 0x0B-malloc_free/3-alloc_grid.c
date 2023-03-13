#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - allocates 2 dimensional array of integers
 * @width: width of grid
 * @height: height of grid
 *
 * Return: pointer to grid
 */

int **alloc_grid(int width, int height)
{
	int i, j, **grid;

	if (width <= 0 || height <= 0)
		return (NULL);
	i = 0;
	grid = (int **) malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);
	while (i < height)
	{
		grid[i] = (int *) malloc(sizeof(int) * height);
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);
			return (NULL);
		}
		while (j < width)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}
