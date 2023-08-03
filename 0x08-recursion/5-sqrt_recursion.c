#include <stdio.h>

/**
 * _sqrt_helper - Helper function to calculate the square root using recursion.
 * @n: The number for which the square root is to be calculated.
 * @guess: The current guess for the square root.
 * Return: The natural square root of n, or -1 if n
 * does not have a natural square root.
 */
int _sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		/* Base case: if the square of guess is equal to n, return guess */
		return (guess);

	if (guess * guess > n)
		return (-1); /* Return -1 if n does not have a natural square root */

	/* Recursively calculate the square root with the next guess */
	return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - Calculates the natural square root
 * of a number using recursion.
 * @n: The number for which the square root is to be calculated.
 * Return: The natural square root of n, or -1 if n
 * does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		/* Return -1 if n is negative (no square root for negative numbers) */
		return (-1);

	/* Start the recursive calculation with initial guess as 0 */
	return (_sqrt_helper(n, 0));
}

