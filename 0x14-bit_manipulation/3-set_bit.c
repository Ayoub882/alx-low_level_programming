#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the number to modify.
 * @index: The index of the bit to set to 1 (0-based).
 *
 * Return: 1 if it worked, or -1 if an error occurs.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1UL << index;
	/*Create a mask with a 1 at the specified index*/

	if (index >= sizeof(unsigned long int) * 8)
		return (-1); /**/

	*n = *n | mask; /*Set the bit to 1*/

	return (1); /*Return 1 to indicate success*/
}


