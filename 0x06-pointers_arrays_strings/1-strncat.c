#include <stdio.h>

/**
* _strncat - Concatenates two strings
*using at most n bytes from src.
* @dest: Pointer to the destination string.
* @src: Pointer to the source string to be appended.
* @n: Maximum number of bytes to be used from src.
* Return: Pointer to the resulting string dest.
*/
char *_strncat(char *dest, char *src, int n)
{
	char *dest_ptr = dest;

	while (*dest_ptr != '\0')
		dest_ptr++;

	while (*src != '\0' && n > 0)
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
		n--;
	}

	*dest_ptr = '\0';

	return (dest);
}
