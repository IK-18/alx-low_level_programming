#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints the name of the file it was compiled from,
 * followed by a new line
 *
 * Return: 0 on succes 1 on failure
 */

int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
