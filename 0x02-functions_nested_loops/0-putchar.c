#include <main.h>
/**
 * main - prints _putchar
 *
 * Return: 0
 */
int main(void)
{
	char string[] = "_putchar";
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		_putchar(string[i]);
	}
	_putchar('\n');
	return (0);
}
