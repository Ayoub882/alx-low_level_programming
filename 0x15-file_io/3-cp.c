#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Exit the program with an error code and print an error message.
 * @code: The error code to exit with.
 * @message: The error message to print.
 */
void error_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}
/**
 * open_source_file - Open the source file and handle errors.
 * @file_from: The source file path.
 * Return: The file descriptor of the source file.
 */
int open_source_file(const char *file_from)
{
	int fd_from = open(file_from, O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		error_exit(98, "Error: Can't read from source file");
	}
	return (fd_from);
}
/**
 * open_destination_file - Open the destination file and handle errors.
 * @file_to: The destination file path.
 * Return: The file descriptor of the destination file.
 */
int open_destination_file(const char *file_to)
{
	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
		error_exit(99, "Error: Can't write to destination file");
	}
	return (fd_to);
}
/**
 * copy_file - Copy the content of one file to another.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 */
void copy_file(int fd_from, int fd_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			error_exit(99, "Error: Can't write to destination file");
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		error_exit(98, "Error: Can't read from source file");
	}
}
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 * Return: 0 on success, exit with appropriate error codes on failure.
 */
int main(int argc, char *argv[])
{
	const char *file_from, *file_to;
	int fd_from, fd_to;

	if (argc != 3)
	{
		error_exit(97, "Usage: cp file_from file_to");
	}

	file_from = argv[1];
	file_to = argv[2];

	fd_from = open_source_file(file_from);
	fd_to = open_destination_file(file_to);

	copy_file(fd_from, fd_to);

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		error_exit(100, "Error: Can't close file descriptor");
	}

	return (0);
}

