#include "sort.h"

/**
 * insertion_sort_list - insertion sort, low numbers go down
 * @list: pointer to the head
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *nextnode, *prevnode;

	if (list == NULL)
		return;

	tmp = (*list)->next;
	while (tmp)
	{
		nextnode = tmp->next;

		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			prevnode = tmp->prev;
			prevnode->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = prevnode;

			tmp->prev = prevnode->prev;
			tmp->next = prevnode;

			if (prevnode->prev)
				prevnode->prev->next = tmp;
			else
				*list = tmp;
			prevnode->prev = tmp;

			print_list(*list);
		}
		tmp = nextnode;
	}
}
