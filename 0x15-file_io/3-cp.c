#include "main.h"

/**
 * copy_file - Copy the content from one file to another.
 * @src_fd: The file descriptor of the source file.
 * @dest_fd: The file descriptor of the destination file.
 * @filename_from: The name of the source file.
 * @filename_to: The name of the destination file.
 *
 * Return: 1 on success, -1 on failure.
 */
int copy_file(int src_fd, int dest_fd, const char *filename_from, const char *filename_to)
{
	int bytes_read, bytes_written;
	char buffer[BUFSIZE];

	while ((bytes_read = read(src_fd, buffer, BUFSIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename_to);
			return (-1);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename_from);
		return (-1);
	}

	return (1);
}

/**
 * main - Entry point for the cp program.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}

	if (copy_file(fd_from, fd_to, argv[1], argv[2]) == -1)
	{
		close(fd_from);
		close(fd_to);
		exit(98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(100);
	}

	return (0);
}

