#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number to modify.
 * @index: The index of the bit to set to 0 (0-based).
 *
 * Return: 1 if it worked, or -1 if an error occurs.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1UL << index;
	/*Create a mask with a 1 at the specified index*/

	if (index >= sizeof(unsigned long int) * 8)
		return (-1); /*Error: index out of range*/


	mask = ~mask; /*Invert the mask to set the bit at index to 0*/

	*n = *n & mask; /*Clear the bit to 0*/

	return (1); /*Return 1 to indicate success*/
}


