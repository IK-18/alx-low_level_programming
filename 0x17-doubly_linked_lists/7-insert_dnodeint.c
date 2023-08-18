#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at
 * a given position
 *
 * @h: head of the list
 * @idx: index of the new node
 * @n: value of the new node
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *tmp;
	unsigned int i;

	new = NULL;
	if (!idx)
		new = add_dnodeint(h, n);
	else
	{
		tmp = *h;
		i = 1;
		if (tmp)
			while (tmp->prev)
				tmp = tmp->prev;
		while (tmp)
		{
			if (i == idx)
			{
				if (!tmp->next)
					new = add_dnodeint_end(h, n);
				else
				{
					new = malloc(sizeof(dlistint_t));
					if (new)
					{
						new->n = n;
						new->next = tmp->next;
						new->prev = tmp;
						tmp->next->prev = new;
						tmp->next = new;
					}
				}
				break;
			}
			tmp = tmp->next;
			i++;
		}
	}
	return (new);
}
