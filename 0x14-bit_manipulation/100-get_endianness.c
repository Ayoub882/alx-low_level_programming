#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 * determine the endianness of a system by
 * checking the value of a multi-byte integer.
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *)&x;

	return (*c == 1);
}


