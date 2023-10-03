#include "main.h"

/**
 * error - Prints an error message and exits the program.
 * @message: The error message to print.
 * @exit_code: The exit code to use when exiting the program.
 */
void error(const char *message, int exit_code)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(exit_code);
}

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		error("Can't close file descriptor", 100);
	}
}

/**
 * copy_file - Copies the contents of one file to another file.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 */
void copy_file(const char *file_from, const char *file_to)
{
	char buffer[1024];
	int from, to;
	ssize_t bytes_read, bytes_written;

	from = open(file_from, O_RDONLY);
	if (from == -1)
	{
		error("Can't read from file", 98);
	}

	to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		close_file(from);
		error("Can't write to file", 99);
	}

	while ((bytes_read = read(from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close_file(from);
			close_file(to);
			error("Can't write to file", 99);
		}
	}

	if (bytes_read == -1)
	{
		close_file(from);
		close_file(to);
		error("Can't read from file", 98);
	}

	close_file(from);
	close_file(to);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 97 for incorrect argument count,
 *98 for file read error,
 *         99 for file write error, and 100 for file close error.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		error("Usage: cp file_from file_to", 97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}

