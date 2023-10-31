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
#include <elf.h>


ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);


char *create_buffer(char *file);
void close_file(int fd);

void checkElfMagic(unsigned char *e_ident);
void printElfMagic(unsigned char *e_ident);
void printElfClass(unsigned char *e_ident);
void printElfData(unsigned char *e_ident);
void printElfVersion(unsigned char *e_ident);
void printElfOsAbi(unsigned char *e_ident);
void printElfType(unsigned int e_type, unsigned char *e_ident);
void printElfEntryPoint(Elf64_Addr e_entry, unsigned char *e_ident);
void closeFile(int fileDescriptor);

#endif /* MAIN_H */


