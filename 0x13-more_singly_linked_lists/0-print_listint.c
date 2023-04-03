#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: list
 *
 * Return: size of list
 */

size_t print_listint(const listint_t *h)
{
	const listint_t *tmp;
	size_t num = 0;

	tmp = h;
	while (tmp)
	{
		num++;
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return (num);
}
