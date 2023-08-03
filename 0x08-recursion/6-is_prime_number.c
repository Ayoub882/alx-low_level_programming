#include <stdio.h>

/**
 * is_prime_helper - Helper function to check if
 * a number is prime using recursion.
 * @n: The number to be checked for primality.
 * @i: The current divisor being tested.
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_helper(int n, int i)
{
	if (n <= 1)
		/* Numbers less than or equal to 1 are not prime */
		return (0);

	if (i * i > n)
		/* If no divisor is found, n is prime */
		return (1);

	if (n % i == 0)
		return (0);

	/* Recursively check with the next divisor */
	return (is_prime_helper(n, i + 1));
}

/**
 * is_prime_number - Determines if a number is prime.
 * @n: The number to be checked for primality.
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	/* Start checking for primality with divisor 2 */
	return (is_prime_helper(n, 2));
}

