#include "sort.h"

/**
 * print_list - Prints all the elements of a listint_t list
 * @list: The list to be printed
 *
 * Description: Goes through each node in the list and prints its integer
 * value, separated by commas and a space.
 */
void print_list(const listint_t *list)
{
	int comma = 0;

	while (list)
	{
		if (comma)
			printf(", ");
		printf("%d", list->n);
		comma = 1;
		list = list->next;
	}
	printf("\n");
}
