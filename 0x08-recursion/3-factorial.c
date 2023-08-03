#include <stdio.h>

/**
 * factorial - Calculates the factorial of a given number using recursion.
 * @n: The number for which factorial is to be calculated.
 * Return: Factorial of the given number, or -1 if n is lower than 0 (error).
 */
int factorial(int n)
{
	if (n < 0)
		return (-1); /* Return -1 to indicate an error for negative values */

	if (n == 0)
		return (1); /* Base case: Factorial of 0 is 1 */

	return (n * factorial(n - 1)); /* Recursively calculate the factorial */
}
