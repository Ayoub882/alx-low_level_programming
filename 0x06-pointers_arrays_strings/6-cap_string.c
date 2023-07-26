#include <stdio.h>

/**
* cap_string - Capitalizes all words of a string.
* @str: Pointer to the string to be capitalized.
* Return: Pointer to the capitalized string.
*/
char *cap_string(char *str)
{
int capitalize_next = 1; /* Start with capitalizing the first character */
int dex;

for (dex = 0; str[dex]; dex++)
{
while (!(str[dex] >= 'a' && str[dex] <= 'z') && !(str[dex] >= 'A'
			&& str[dex] <= 'Z') && str[dex] != '\0')
dex++;

if (capitalize_next && str[dex] >= 'a' && str[dex] <= 'z')
{
str[dex] -= 32; /* Capitalize the current character */
}

/* Set capitalize_next based on the encountered separators */
if (str[dex] == ' ' || str[dex] == '\t' || str[dex] == '\n' ||
str[dex] == ',' || str[dex] == ';' || str[dex] == '.' || str[dex] == '!' ||
str[dex] == '?' || str[dex] == '"' || str[dex] == '(' || str[dex] == ')' ||
str[dex] == '{' || str[dex] == '}')
{
capitalize_next = 1; /* Next character should be capitalized */
}
else
{
capitalize_next = 0; /* Next character should not be capitalized */
}
}

return (str);
}

