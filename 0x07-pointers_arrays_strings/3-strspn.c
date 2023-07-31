#include "main.h"
#include <stddef.h>
/**
* _strspn - Gets the length of a prefix substring.
* @s: Pointer to the string to search.
* @accept: Pointer to the substring containing the accepted bytes.
*
* Return: The number of bytes in the initial segment of s which consist
*         only of bytes from accept.
*/
unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;

while (*s && _strchr(accept, *s))
{
count++;
s++;
}

return (count);
}

/**
 * _strchr - Locate a character in a string.
 * @s: Pointer to the string to search.
 * @c: The character to locate.
 *
 * Return: Pointer to the first occurrence of the character c in the string s,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);

s++;
}

if (*s == c)
return (s);

return (NULL);
}

