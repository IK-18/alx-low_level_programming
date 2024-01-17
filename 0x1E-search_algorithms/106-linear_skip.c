#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: the first index where value is located
 * If value is not present in list or if list is NULL,
 * your function must return NULL
 */
skiplist_t *linear_skip(skiplist_t *list,int value)
{
	skiplist_t *tmp1 = list, *tmp2 = list;

	if (!tmp1)
		return (NULL);
	while (tmp1->n <= value)
	{
		printf("Value checked at index[%ld] = [%d]\n", tmp1->index, tmp1->n);
		if (tmp1->n == value)
			return (tmp1);
		if (tmp2->express)
			tmp2 = tmp2->express;
		else if (tmp2->next)
			tmp2 = tmp1->next;
		if (tmp2->n >= value || !tmp1->next || !tmp1->express
		    || !tmp2->next)
			break;
		if (tmp1->express)
			tmp1 = tmp1->express;
		else if (tmp1->next)
			tmp1 = tmp1->next;
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
		tmp1->index, tmp2->index);
	while (tmp1->next)
	{
		printf("Value checked at index[%ld] = [%d]\n", tmp1->index, tmp1->n);
		if (tmp1->n == value)
			return (tmp1);
		if (tmp1->next)
			tmp1 = tmp1->next;
		else
			break;
	}
	printf("Value checked at index[%ld] = [%d]\n", tmp1->index, tmp1->n);
	if (tmp1->n == value)
		return (tmp1);
	return (NULL);
}
