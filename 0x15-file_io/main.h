#ifndef MAIN_H
#define MAIN_H

#define BUFSIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);



void error(const char *message, int exit_code);
void close_file(int fd);

void copy_file(const char *file_from, const char *file_to);


/*int copy_file(int src_fd, int dest_fd, const char *filename_from, const char *filename_to);

int open_source_file(const char *file_name);
int open_destination_file(const char *file_name);
void copy_contents(int fd_from, int fd_to);
void close_files(int fd_from, int fd_to);*/

#endif /* MAIN_H */

