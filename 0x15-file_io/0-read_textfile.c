#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 * 
 * Return: the number of letters printed, or 0 if it failed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t oFile, rFile, wFile;
	char *buff;
	if (!filename)
		return (0);
	oFile = open(filename, O_RDONLY);
	if (oFile < 0)
		return (0);
	buff = malloc(sizeof(char) * letters);
	if (!buff)
		return (0);
	rFile = read(oFile, buff, letters);
	if (rFile < 0)
	{
		free(buff);
		return (0);
	}
	buff[rFile] = '\0';
	close(oFile);
	wFile = write(STDOUT_FILENO, buff, rFile);
	if (wFile < 0)
	{
		free(buff);
		return (0);
	}
	free(buff);
	return (wFile);
}
