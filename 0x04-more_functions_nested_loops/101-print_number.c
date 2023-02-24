#include "main.h"

/**
 * print_number - prints a number
 * @n: digit to print
 * Return: the number
 */

void print_number(int n)
{
	int th, h, t, d;

	if (n < 0)
	{
		n = -n;
		_putchar(45);
	}
	if (n > 1000)
	{
		th = n / 1000;
		_putchar(th + '0');
	}
	if (n > 100)
	{
		h = n / 100;
		if (h >= 10)
			h = h % 10;
		d = n % 100;
		_putchar(h + '0');
	}
	if (n > 10)
	{
		t = n / 10;
		if (t >= 10)
			t = t % 10;
		d = n % 10;
		_putchar(t + '0');
	}
	else
		d = n % 10;
	_putchar(d + '0');
	_putchar('\n');
}
