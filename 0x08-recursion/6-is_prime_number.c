 #include "main.h"

/**
 * is_prime - checks if number is prime
 * @n: number
 * @i: tester
 *
 * Return: if prime or not
 */
int is_prime(int n, int i)
{
	if ((n % i == 0 && n != i) || n <= 1)
	{
		return (0);
	}
	if (i == n)
	{
		return (1);
	}
	return (is_prime(n, i + 1));
}

/**
 * is_prime_number - checks if number is prime
 * @n: number
 *
 * Return: 1 if prime or 0 if not prime
 */

int is_prime_number(int n)
{
	return (is_prime(n, 2));
}
