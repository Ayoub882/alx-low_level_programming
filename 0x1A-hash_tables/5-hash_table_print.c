#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	if (ht == NULL)
		return;

	int first_pair = 1;
	/* Flag to track the first key/value pair */

	printf("{");
	for (unsigned long int i = 0; i < ht->size; ++i)
	{
		hash_node_t *current = ht->array[i];

		while (current != NULL)
		{
			if (!first_pair)
				printf(", ");

			printf("'%s': '%s'", current->key, current->value);
			first_pair = 0;
			current = current->next;
		}
	}
	printf("}\n");
}
