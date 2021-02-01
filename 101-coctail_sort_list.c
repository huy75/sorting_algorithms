#include "sort.h"

/**
 * list_len - returns the number of elements in a list
 * @h: points to the head of list
 * Return: size_t
 */
size_t list_len(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes += 1;
		h = h->next;
	}
	return (nodes);
}

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
 * cocktail_sort_list - function sorts a doubly linked list
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int swapped = 1;

	if (!list || !*list || list_len(*list) < 2)
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
				swap_list(p, p->next);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (!swapped)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				swapped = 1;
				p = p->prev;
				swap_list(p->next, p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
