#include "main.h"

/**
 * get_endianness - checks the type of endianness
 * Return: 0 if big endian and 1 if little endian
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *c = (char *) &n;

	return (*c);
}

