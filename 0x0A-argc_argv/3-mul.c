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
	int i, product;

	product = 1;
	while (argc-- && argc > 0)
	{
		i = atoi(argv[argc]);
		product = product * i;
	}
	printf("%d\n", product);
	return (0);
}
