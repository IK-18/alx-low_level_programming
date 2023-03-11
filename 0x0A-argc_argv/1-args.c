#include <stdio.h>
#include "main.h"

/**
 * main - prints the number of arguments passed into it
 * @argc: number of arguments passed into main
 * @argv: array containing arguments passed into main
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (argc--)
	{
		if (argv[argc] != argv[0])
			i++;
	}
	printf("%d\n", i);
	return (0);
}

