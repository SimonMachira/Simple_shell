#include "main.h"

/**
 * free_stat_buff - free list
 * @head: list pointer
 */

void free_stat_buff(buff_list **head)
{
	buff_list *now;

	if (head)
	{
		now = *head;
		*head = (*head)->next;
		if (now->buff_ptr)
			free(now->buff_ptr);
		free(now);
	}
	*head = NULL;
}
