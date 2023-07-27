#include <stdio.h>
#include "main.h"

/**
* infinite_add - Adds two numbers.
* @n1: Pointer to the first number (null-terminated string).
* @n2: Pointer to the second number (null-terminated string).
* @r: Pointer to the buffer to store the result.
* @size_r: Size of the buffer @r.
*
* Return: Pointer to the result (stored in a dynamically allocated memory)
*or NULL if the result cannot fit.
*/
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int len1 = 0, len2 = 0;
while (n1[len1] != '\0')
len1++;
while (n2[len2] != '\0')
len2++;

if (size_r <= len1 || size_r <= len2 || size_r == 0)
return (NULL);

r[size_r - 1] = '\0';
int i = len1 - 1;
int j = len2 - 1;
int k = size_r - 2;
int carry = 0;

while (i >= 0 || j >= 0 || carry > 0)
{
int sum = carry;
if (i >= 0)
sum += n1[i] - '0';
if (j >= 0)
sum += n2[j] - '0';

carry = sum / 10;
if (k < 0)
return (NULL);

r[k] = (sum % 10) + '0';

i--;
j--;
k--;
}

return (&r[k + 1]);
}

