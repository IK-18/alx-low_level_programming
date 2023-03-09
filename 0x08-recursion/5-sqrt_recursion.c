#include "main.h"

/**
 * _sqrt - solves square root of a number
 * @n: number
 * @i: root
 *
 * Return: square root of number
 */

int _sqrt(int n, int i)
{
	if (n < 0)
		return (-1);
	if ((i * i) > n)
		return (-1);
	if ((i * i) == n)
		return (i);
	return (_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - solves square root
 * @n: number
 *
 * Return: root
 */

int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}
