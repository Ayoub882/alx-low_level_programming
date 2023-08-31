#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/* Structure for singly linked list */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/* Function to convert binary to unsigned int */
unsigned int binary_to_uint(const char *b);

/* Custom _putchar function */
int _putchar(char c);

#endif /* MAIN_H */

