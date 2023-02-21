#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * main - prints alphabet
 *
 * Return: 0
 */
int main(void)
{
	char c = 'a';
	int i;

	for (i = 1; i <= 10; i++)
	{
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
	}
	_putchar('\n');
	return (0);
}
