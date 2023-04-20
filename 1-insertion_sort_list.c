#include "sort.h"
void swap(listint_t **list, listint_t *node);

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 *
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		tmp = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			swap(list, current);
			print_list(*list);
		}
		current = tmp;
	}
}

/**
 * swap - swaps two nodes in a doubly linked list
 * @list: list to swap nodes in
 * @node: first node to swap
 */
void swap(listint_t **list, listint_t *node)
{
	node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	node->next = node->prev;
	node->prev = node->prev->prev;
	node->next->prev = node;

	if (!node->prev)
		*list = node;
	else
		node->prev->next = node;
}
