#include "main.h"

/**
 * main - copies the content of a file to another file
 * @ac: number of arguments passed to the program
 * @av: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char *av[])
{
	int src, dest, i, a, b;
	char buf[BUFSIZ];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	src = open(av[1], O_RDONLY);
	if (src < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	dest = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((i = read(src, buf, BUFSIZ)) > 0)
	{
		if (dest < 0 || write(dest, buf, i) != i)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			close(src);
			exit(99);
		}
	}
	if (i < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	a = close(src);
	b = close(dest);
	if (a < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src);
		exit(100);
	}
	if (b < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest);
		exit(100);
	}
	return (0);
}

