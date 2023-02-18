#include <stdio.h>
/**
 * main - print all single digit numbers starting from 0 followed by a new line
 * Return: 0
 */
int main(void)
{
	int i = 0;

	char c = 'a';

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0');
	}
	putchar('\n');
	return (0);
}

