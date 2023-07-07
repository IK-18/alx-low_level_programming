#include "main.h"

/**
 * binary_to_uint - coverts a binary to an unsigned int
 * @b: binary string
 *
 * Return: converted value
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int dec = 0;
	int len = 0, pow = 1;

	if (!b)
		return (0);

	while (b[len] != '\0')
		len++;

	while (len--)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
		dec += ((b[len] - '0') * pow);
		pow *= 2;
	}
	return (dec);
}
