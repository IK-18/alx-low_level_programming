#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: string
 * Return: Always 0
 */

void puts_half(char *str)
{
	int len, i;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	if (len % 2 == 0)
	{
		i = len / 2;
		while (i < len)
		{
			_putchar(str[i]);
			i++;
		}
	}
	else
	{
		i = (len - 1) / 2;
		while (i < len)
		{
			_putchar(str[i]);
			i++;
		}
	}
	_putchar('\n');
}
