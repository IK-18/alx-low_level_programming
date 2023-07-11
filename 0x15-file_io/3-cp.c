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
 * main - copy a file's contents to another file
 * @argc: the argument count
 * @argv: the argument values
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Can't read file");
		exit(98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Can't write file");
		exit(99);
	}
	while ((bytes_read = _read(argv[1], fd_from, buffer, BUFFER_SIZE)))
	{
		if (bytes_read == -1)
		{
			_close(fd_from);
			_close(fd_to);
			exit(98);
		}
		bytes_written = _write(argv[2], fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			_close(fd_from);
			_close(fd_to);
			exit(99);
		}
	}
	if ((_close(fd_from) | _close(fd_to)) < 0)
		exit(100);
	return (0);
}
