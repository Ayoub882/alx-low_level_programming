#include "main.h"
#include <stdio.h>

/**
 * positive_or_negative - Determines the sign of an integer and prints a message.
 *
 * @i: The integer to be evaluated.
 *
 * Description: This function checks the sign of the input integer @i.
 *              If @i is greater than zero, it prints "i is positive."
 *              If @i is less than zero, it prints "i is negative."
 *              If @i is equal to zero, it prints "i is zero."
 */

void positive_or_negative(int i)
{
	if (i < 0)
	{
		printf("%d is negative", i);
	}
	else if (i > 0)
	{
		printf("%d is positive", i);
	}
	else
	{
		printf("%d is zero", i);
	}
}
