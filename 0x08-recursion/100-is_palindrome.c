#include <stdio.h>
#include <string.h>

/**
 * is_palindrome_helper - Helper function to check if
 * a string is a palindrome using recursion.
 * @s: The input string to be checked.
 * @start: The starting index of the current substring to compare.
 * @end: The ending index of the current substring to compare.
 * Return: 1 if the substring is a palindrome, 0 otherwise.
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1); /* Base case: Substring is a palindrome */

	if (s[start] != s[end])
		/* If characters at the start and end do not match, it's not a palindrome */
		return (0);

	/* Recursively check the next substring */
	return (is_palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The input string to be checked.
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int length = strlen(s);

	if (length == 0)
		return (1); /* Empty string is a palindrome */

	/* Start checking from the first and last characters */
	return (is_palindrome_helper(s, 0, length - 1));
}

