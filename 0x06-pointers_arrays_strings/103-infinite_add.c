#include <stdio.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int len1 = strlen(n1);
int len2 = strlen(n2);
int carry = 0;
int i, j, k;

/* Check if the result can be stored in the buffer */
if (len1 + len2 >= size_r - 1)
return 0;

/* Initialize the result buffer with null characters */
for (i = 0; i < size_r; i++)
r[i] = '\0';

/* Perform addition from right to left (rightmost digits) */
for (i = len1 - 1, j = len2 - 1, k = size_r - 2; i >= 0 || j >= 0 || carry; i--, j--, k--)
{
int digit1 = (i >= 0) ? n1[i] - '0' : 0;
int digit2 = (j >= 0) ? n2[j] - '0' : 0;
int sum = digit1 + digit2 + carry;

carry = sum / 10;
r[k] = (sum % 10) + '0';
}

/* Move the result to the beginning of the buffer */
for (i = 0; r[i] == '0'; i++)
;

/* If the result is zero, set it to "0" */
if (r[i] == '\0')
{
r[0] = '0';
r[1] = '\0';
}
else
{
/* Shift the result to the beginning of the buffer */
int len = strlen(&r[i]);
memmove(r, &r[i], len + 1);
}

return (r);
}
