#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the function should read and print.
 *
 * Return: 0 if the function fails or filename is NULL.
 * O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t oFile, rFile, wFile;
	char *buff;

	if (!filename)
		return (0);

	oFile = open(filename, O_RDONLY);

	buff = malloc(sizeof(char) * letters);
	if (!buff)
		return (0);
	rFile = read(oFile, buff, letters);
	wFile = write(STDOUT_FILENO, buff, rFile);

	if (oFile == -1 || rFile == -1 || wFile == -1 || wFile != rFile)
	{
		free(buff);
		return (0);
	}

	free(buff);
	close(oFile);

	return (wFile);
}

