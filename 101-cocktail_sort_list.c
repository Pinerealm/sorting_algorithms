#include "sort.h"
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: the doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *tmp, *end;

	if (!list || !*list || !(*list)->next)
		return;
	end = *list;
	while (end->next)
		end = end->next;

	while (swapped)
	{
		swapped = 0;
		tmp = *list;
		while (tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(list, tmp, tmp->next);
				print_list(*list);
				swapped = 1;
			}
			else
				tmp = tmp->next;
		}
		if (!swapped)
			break;
		swapped = 0;

		while (tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_nodes(list, tmp->prev, tmp);
				print_list(*list);
				swapped = 1;
			}
			else
				tmp = tmp->prev;
		}
	}
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: the doubly linked list
 * @node1: the first node
 * @node2: the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
