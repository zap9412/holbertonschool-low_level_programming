#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * _close - closes a file descriptor and handles errors
 * @fd: file descriptor
 *
 * Return: 0 on success, exits with code 100 on error
 */
int _close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	return (0);
}

/**
 * main - copies content of one file to another
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, exits with error codes otherwise
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r;
	char *buffer;
	char *file_from, *file_to;
	ssize_t to_write, written, write_ret;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = av[1];
	file_to = av[2];

	buffer = malloc(BUF_SIZE);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		free(buffer);
		exit(98);
	}

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		free(buffer);
		_close(fd_from);
		exit(99);
	}

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		to_write = r;
		written = 0;

		while (to_write > 0)
		{
			write_ret = write(fd_to, buffer + written, to_write);
			if (write_ret == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
				free(buffer);
				_close(fd_from);
				_close(fd_to);
				exit(99);
			}

			written += write_ret;
			to_write -= write_ret;
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		free(buffer);
		_close(fd_from);
		_close(fd_to);
		exit(98);
	}

	free(buffer);
	_close(fd_from);
	_close(fd_to);

	return (0);
}
