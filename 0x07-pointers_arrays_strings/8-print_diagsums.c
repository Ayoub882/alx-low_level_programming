#include <stdio.h>

/**
* print_diagsums - Prints the sum of the two diagonals of a square matrix.
* @a: Pointer to the square matrix of integers.
* @size: Size of the square matrix.
*/
void print_diagsums(int *a, int size)
{
int sum1 = 0, sum2 = 0;
int i;

for (i = 0; i < size; i++)
{
/* Sum of elements in the main diagonal (top-left to bottom-right)*/
sum1 += a[i * size + i];
/* Sum of elements in the secondary diagonal (top-right to bottom-left)*/
sum2 += a[i * size + (size - 1 - i)];
}

printf("Sum of main diagonal: %d\n", sum1);
printf("Sum of secondary diagonal: %d\n", sum2);
}

