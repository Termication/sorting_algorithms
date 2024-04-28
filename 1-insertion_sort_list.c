#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 *
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = *list;

	for (; current; current = current->next)
	{
		for (; current->prev && current->n < current->prev->n;)
		{
			temp = current->prev;
			current->prev = temp->prev;
			temp->next = current->next;

			if (current->next)
				current->next->prev = temp;

			if (temp->prev)
				temp->prev->next = current;
			else
				*list = current;

			temp->prev = current;
			current->next = temp;

			print_list(*list);
		}
	}
}
