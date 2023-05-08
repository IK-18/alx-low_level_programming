#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file
 * @text_content: text in the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int openFile, writeFile, length = 0;

	if (!filename)
		return (-1);

	openFile = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (openFile < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[length])
			length++;
		writeFile = write(openFile, text_content, length);
		if (writeFile != length)
			return (-1);
	}

	close(openFile);

	return (1);
}

