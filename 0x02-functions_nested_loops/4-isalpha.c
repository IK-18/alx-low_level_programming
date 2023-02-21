#include "isalpha.h"
/**
 * _isalpha - Return 1 if it is an alphabet, 0 if not.
 * @c: char type letter
 * Return: 1 if alphabet, 0 if not
 */
int _isalpha(int c)
{
	if (c >= 65 && c <= 122)
		return (1);
	else
		return (0);
}
