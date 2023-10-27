#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: Pointer to the binary string.
 *
 * Return: The converted number or 0 if invalid input.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b == '0' || *b == '1')
		{
			result = (result << 1) | (*b - '0'); /* Shift and add the binary digit */
			b++;
		}
		else
		{
			return (0);
		}
	}

	return (result);
}


