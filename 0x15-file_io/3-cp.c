#include "main.h"
#define BUFFER_SIZE 1024

/**
 * _close - close a file descriptor and print an error message if it fails
 * @fd: file descriptor
 *
 * Return: 0 upon success, -1 upon failure
 */
int _close(int fd)
{
	if (close(fd) == 0)
		return (0);
	dprintf(STDERR_FILENO, "Error: Failed to close fd %d\n", fd);
	return (-1);
}

/**
 * _read - read from a file and print an error message if it  fails
 * @filename: the name of the file to be read
 * @fd: file descriptor
 * @buf: buffer
 * @count: the number of bytes to read
 *
 * Return: The number of bytes read, or -1 upon failure
 */
ssize_t _read(const char *filename, int fd, char *buf, size_t count)
{
	ssize_t bytes_read = read(fd, buf, count);

	if (bytes_read > -1)
		return (bytes_read);
	dprintf(STDERR_FILENO, "Error: Failed to read file %s\n", filename);
	return (-1);
}

/**
 * _write - write to a file and print an error message upon failure
 * @filename: the name of the file to write to
 * @fd: the file descriptor to write to
 * @buf: buffer
 * @count: the number of bytes to write
 *
 * Return: The number of bytes written, or -1 upon failure
 */
ssize_t _write(const char *filename, int fd, const char *buf, size_t count)
{
	ssize_t bytes_written = write(fd, buf, count);

	if (bytes_written > -1)
		return (bytes_written);
	dprintf(STDERR_FILENO, "Error: Failed to write to %s\n", filename);
	return (-1);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, i, a, b;
	char buf[BUFSIZ];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	while ((i = _read(fd_from, buf, BUFSIZ)) > 0)
	{
		if (fd_to < 0 || _write(fd_to, buf, i) != i)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			_close(fd_from);
			exit(99);
		}
	}
	if (i < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	a = _close(fd_from);
	b = _close(fd_to);
	if (a < 0 || b < 0)
		exit(100);
	return (0);
}
