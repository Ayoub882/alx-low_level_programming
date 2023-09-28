#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to extract the bit from.
 * @index: The index of the bit to retrieve (0-based).
 *
 * Return: The value of the bit at the specified index,
 * or -1 if an error occurs.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;
	/*Create a mask with a 1 at the specified index*/

	if (index >= sizeof(unsigned long int) * 8)
		return (-1); /*Error: index out of range*/


	if ((n & mask) == 0)
		return (0); /* The bit is 0 */
	else
		return (1); /* The bit is 1 */
}

