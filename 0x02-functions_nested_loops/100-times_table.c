#include <stdio.h>
#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The number to generate the times table for.
 */
void print_times_table(int n)
{
	if (n < 0 || n > 15)
	{
		return;
	}

	int i, j, res;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			res = i * j;
			if (j == 0)
				printf("%d", res);
			else
				printf("%4d", res);
			if (j < n)
				printf(",");
		}
		printf("\n");
	}
}
