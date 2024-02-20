#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 *
 * Description: Swaps nodes and prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			temp->next = current->next;
			current->next = temp;
			if (temp->next != NULL)
				temp->next->prev = temp;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			temp->prev = current;
			print_list(*list);
		}
	}
}
