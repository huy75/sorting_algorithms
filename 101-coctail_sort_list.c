#include "sort.h"

/**
 * swap_list - Swaps linked list node with the following node
 * @list: list
 * @a: pointer to node a
 * @b: pointer to node b
 */
void swap_next(listint_t **list, listint_t *a, listint_t *b)
{
	
	if (b->next)
		a->next = b->next;
	else
		a->next = NULL;

	if (a->prev)
		b->prev = a->prev;
	else
		(*list) = b;

	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - function sorts a doubly linked list
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p, *q;
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	p = *list;
	while (swapped)
	{
		swapped = 0;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				swapped = 1;
				q = &p->next;
				swap_next(list, &p, &q);
				print_list(*list);
			}
			else
				p = p->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		p = p->prev;

		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				swapped = 1;
				q = &p->next;
				swap_next(list, &p, &q);
				print_list(*list);
			}
			else
				p = p->prev;
		}

	}
}
