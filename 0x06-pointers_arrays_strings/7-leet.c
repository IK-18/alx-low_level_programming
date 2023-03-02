#include "main.h"

/**
 * driver - encodes a strnig
 * @s: string to be encoded
 * Return: encoded script
 */

char *encoder(char *s)
{
	
	int i, j;

	char *a = "aAeEoOtTlL";
	char *b = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (s[i] == a[j])
			{
				s[i] = b[j];
			}
		}
	}

	return (s);
}
