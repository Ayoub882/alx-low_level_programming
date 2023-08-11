#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
/**
 * error_exit - Print an error message and exit with status 98.
 */
void error_exit(void)
{
    printf("Error\n");
    exit(98);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	char *num1;
	char *num2;
	int i, j;
	int len1, len2;
	int result_len;
	int *result;
	int carry;
	int n1, n2;
	int product;
	int start;

	if (argc != 3)
		error_exit();

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; num1[i]; i++)
	{
		if (!isdigit(num1[i]))
			error_exit();
	}

	for (i = 0; num2[i]; i++)
	{
		if (!isdigit(num2[i]))
			error_exit();
	}

	len1 = 0, len2 = 0;
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result_len = len1 + len2;
	result = calloc(result_len, sizeof(int));

	if (result == NULL)
		error_exit();

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			product = (n1 * n2) + result[i + j + 1] + carry;

			carry = product / 10;
			result[i + j + 1] = product % 10;
		}

		result[i] += carry;
	}

	start = 0;
	while (start < result_len && result[start] == 0)
		start++;

	if (start == result_len)
		printf("0");
	else
	{
		for (i = start; i < result_len; i++)
			printf("%d", result[i]);
	}
	printf("\n");

	free(result);
	return (0);
}

