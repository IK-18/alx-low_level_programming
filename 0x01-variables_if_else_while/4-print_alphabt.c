#include <stdio.h>
/**
 * main - prints all letters aside q and e using puchar
 * Return: 0
 */
int main(void)
{
	int c = 'a';

	while (c <= 'z')
	{
		if (c != 'q' && c != 'e')
		{
			putchar(c);
		}
	}
	putchar('\n');
	return (0);
}
