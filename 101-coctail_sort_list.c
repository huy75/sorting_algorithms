#include "sort.h"

/**
 * swap_node - swap nodes on a linked list
 * @n1 : num 1
 * @n2: num 2
 */
void swap_node(listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	if (n2->next)
		n2->next->prev = n1;
	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}

/**
 * cocktail_sort_list - function sorts a doubly linked list
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
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
				swap_node(p, p->next);
				if (!p->prev->prev)
					*list = p->prev;
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
				swap_node(p->prev, p);
				if (!p->prev)
					*list = p;
				print_list(*list);
			}
			else
				p = p->prev;
		}

	}
}
