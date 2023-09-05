#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"

/**
 * main - Copies the content of one file to another
 * @argc: The number of arguments
 * @argv: An array of arguments
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd_from = open_source_file(argv[1]);
	fd_to = open_destination_file(argv[2]);

	copy_contents(fd_from, fd_to);
	close_files(fd_from, fd_to);

	return (0);
}

/**
 * open_source_file - Open the source file for reading and handle errors.
 * @file_name: The name of the source file.
 * Return: The file descriptor of the source file, or -1 on error.
 */
int open_source_file(const char *file_name)
{
	int fd_from = open(file_name, O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
		exit(98);
	}
	return (fd_from);
}

/**
 * open_destination_file - Open the destination file for writing and handle errors.
 * @file_name: The name of the destination file.
 * Return: The file descriptor of the destination file, or -1 on error.
 */
int open_destination_file(const char *file_name)
{
	int fd_to = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
		exit(99);
	}
	return (fd_to);
}

/**
 * copy_contents - Copy the contents of one file to another.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 */
void copy_contents(int fd_from, int fd_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		exit(98);
	}
}

/**
 * close_files - Close the source and destination files and handle errors.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n",
				(close(fd_from) == -1) ? fd_from : fd_to);
		exit(100);
	}
}

