#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - multiplies two numbers
 * @argc: number of arguments passsed into main
 * @argv: array containnig all the arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int i, j, product;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	product = i * j;
	printf("%d\n", product);
	return (0);
}
