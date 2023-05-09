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

	if (filename == NULL)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (!buff)
		return (0);

	oFile = open(filename, O_RDONLY);
	rFile = read(oFile, buff, letters);
	buff[rFile] = '\0';
	close(oFile);
	wFile = write(STDOUT_FILENO, buff, rFile);

	if (oFile < 0 || rFile < 0 || wFile < 0 || wFile != rFile)
	{
		free(buff);
		return (0);
	}

	free(buff);
	return (wFile);
}
