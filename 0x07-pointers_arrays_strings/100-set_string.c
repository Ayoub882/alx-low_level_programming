#include <stdio.h>
#include "main.h"

/**
* set_string - Sets the value of a pointer to a char.
* @s: Pointer to the pointer that needs to be set.
* @to: Pointer to the char that will be set.
*/
void set_string(char **s, char *to)
{
*s = to;
}
