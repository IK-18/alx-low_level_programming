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
                h = (n / 100) % 10;
                t = (n / 10) % 10;
                d = n % 1000;
                _putchar(th + '0');
        }
        else if (n > 100)
        {
                h = n / 100;
                t = (n / 10) % 10;
                d = n % 100;
                _putchar(h + '0');
        }
        else if (n > 10)
        {
                t = n / 10;
                d = n % 10;
                _putchar(t + '0');
        }
        else
                d = n % 10;
        _putchar(d + '0');
}
