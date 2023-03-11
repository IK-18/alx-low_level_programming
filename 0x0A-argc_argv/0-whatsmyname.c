#include <stdio.h>
#include "main.h"

/**
 * main - print its name
 *@argc: number of arguments passed into main
 *@argv: array containing all arguments passed into main
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	while (argc--)
	{
		if (argc == 0)
			printf("%s\n", argv[argc]);
	}
	return (0);
}
