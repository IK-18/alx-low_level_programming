#include "main.h"

/**
 * puts2 - prints very other character of a string
 * @str: string
 * Return: Always 0
 */

void puts2(char *str)
{
	int i, len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
