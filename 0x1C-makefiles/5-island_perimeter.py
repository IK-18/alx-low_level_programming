#!/usr/bin/python3


def island_perimeter(grid):
    """Returns the perimeter of the island
    described in grid.
    """

    size = 0
    height = len(grid) - 1
    width = len(grid[0]) - 1

    for a, i in enumerate(grid):
        for b, j in enumerate(r):
            if j == 1:
                if a == 0 or grid[a - 1][b] != 1:
                    size += 1
                if b == 0 or grid[a][b - 1] != 1:
                    size += 1
                if b == width or grisd[a][b + 1] != 1:
                    size += 1
                if a == height or grid[a + 1][b] != 1:
                    size += 1
    return size
