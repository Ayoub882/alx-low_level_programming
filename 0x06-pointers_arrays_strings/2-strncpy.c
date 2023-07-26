#include <stdio.h>

/**
* _strncpy - Copies a string, up to n bytes, from src to dest.
* @dest: Pointer to the destination buffer.
* @src: Pointer to the source string to be copied.
* @n: Maximum number of bytes to be copied from src.
* Return: Pointer to the resulting string dest.
*/
char *_strncpy(char *dest, char *src, int n)
{
char *dest_ptr = dest;

/**
  *Copy characters from src to dest, up to n bytes
  */
while (*src != '\0' && n > 0)
{
*dest_ptr = *src;
dest_ptr++;
src++;
n--;
}

/**
  *If n is greater than the length of src, pad with null bytes
  */
while (n > 0)
{
*dest_ptr = '\0';
dest_ptr++;
n--;
}

return (dest);
}
