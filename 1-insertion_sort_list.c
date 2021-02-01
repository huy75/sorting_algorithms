#include "sort.h"

/**
 * swap_list - Swaps linked list nodes then prints list
 * @a: First node
 * @b: Second node
 */
void swap_list(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pivot, *cur;

	if (!list || !*list || !(*list)->next)
		return;

	pivot = (*list)->next;

	while (pivot)
	{
		cur = pivot;
		pivot = pivot->next;
		while (cur && cur->prev)
		{
			if (cur->prev->n > cur->n)
			{
				swap_list(cur->prev, cur);
				if (!cur->prev)
					*list = cur;
				print_list((listint_t *)*list);
			}
			else
				cur = cur->prev;
		}
	}
}
