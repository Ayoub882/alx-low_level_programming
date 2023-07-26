#include <stdio.h>

/**
* _strcmp - Compares two strings.
* @s1: Pointer to the first string.
* @s2: Pointer to the second string.
* Return: An integer less than, equal to, or greater than 0, depending on
* whether s1 is less than, equal to, or greater than s2.
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s1 == *s2)
{
s1++;
s2++;
}

return (*s1 - *s2);
}

