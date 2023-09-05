#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * display_error - Display an error message
 * and exit with the given status code.
 * @message: The error message to display.
 * @status: The status code to exit with.
 */
void display_error(const char *message, int status)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(status);
}

/**
 * copy_file - Copy the content of one file to another.
 * @source: The source file descriptor.
 * @dest: The destination file descriptor.
 */
void copy_file(int source, int dest)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(source, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(dest, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			display_error("Error: Can't write to destination file", 99);
		}
	}

	if (bytes_read == -1)
	{
		display_error("Error: Can't read from source file", 98);
	}
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		display_error("Usage: cp file_from file_to", 97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		display_error("Error: Can't read from source file", 98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		display_error("Error: Can't write to destination file", 99);
	}

	copy_file(fd_from, fd_to);

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		display_error("Error: Can't close file descriptor", 100);
	}

	return (0);
}

