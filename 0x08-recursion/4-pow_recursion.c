#include <stdio.h>

/**
 * _pow_recursion - Calculates the value of x raised
 *to the power of y using recursion.
 * @x: The base number.
 * @y: The exponent.
 * Return: The result of x^y, or -1 if y is lower than 0 (error).
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1); /* Return -1 to indicate an error for negative exponents */

	if (y == 0)
		return (1); /* Base case: x raised to power 0 is 1 */

	return (x * _pow_recursion(x, y - 1)); /* Recursively calculate x^y */
}

