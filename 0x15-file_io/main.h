#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stddef.h>
#include <unistd.h>

/* Function prototypes */
int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _strlen(char *str);
void close_file(int fd);

/*New functions prototypes*/
int open_source_file(const char *file_name);
int open_destination_file(const char *file_name);
void copy_contents(int fd_from, int fd_to);
void close_files(int fd_from, int fd_to);

#endif /* MAIN_H */

