#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the new dog, or NULL if allocation fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog_ptr;
	char *name_copy, *owner_copy;

	/* Allocate memory for the new dog structure */
	new_dog_ptr = malloc(sizeof(dog_t));
	if (new_dog_ptr == NULL)
		return (NULL);

	/* Allocate memory for name and owner copies */
	name_copy = malloc(sizeof(char) * (strlen(name) + 1));
	owner_copy = malloc(sizeof(char) * (strlen(owner) + 1));
	if (name_copy == NULL || owner_copy == NULL)
	{
		free(new_dog_ptr);
		free(name_copy);
		free(owner_copy);
		return (NULL);
	}

	/* Copy name and owner strings */
	strcpy(name_copy, name);
	strcpy(owner_copy, owner);

	/* Assign values to the new dog structure */
	new_dog_ptr->name = name_copy;
	new_dog_ptr->age = age;
	new_dog_ptr->owner = owner_copy;

	return (new_dog_ptr);
}

