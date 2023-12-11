#include "main.h"

/**
 * mal_alloc - creation and allocation of memory space
 * @val: size of memory allocated
 * @pointer: memory pointer
 * Return: pointer else NULL
 */

char *mal_alloc(char *pointer, size_t val)
{
	pointer = new_alloc(pointer, val);

	if (!(pointer))
	{
		perror("hsh");
		buff_free(&buff_head);
		return (NULL);
	}

	buff_head = new_buff(&buff_head);
	return (pointer);
}

/**
 * new_alloc - reallocates memory
 * @pointer: old pointer to memery
 * @buffsize_new: new memory size
 * Return: pointer to new memory else old pointer
 */

char *new_alloc(char *pointer, size_t buffsize_new)
{
	size_t before = strn_len(pointer);
	size_t k = 0;
	char *buff_ptr;

	if (buffsize_new == before)
		return (pointer);
	if (buffsize_new == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}
	buff_ptr = malloc(buffsize_new);
	if (!buff_ptr)
		return (NULL);
	if (pointer)
	{
		for (k = 0; k < before && k < buffsize_new; k++)
			*(b uff_ptr + k) = *(pointer + k);

		free(pointer);
	}

	buff_set((buff_ptr + before), 0, (buffsize_new - before));
	return (buff_ptr);
}

/**
 * buff_free - freememory
 * @head: argument passed
 */

void buff_free(buff_list **head)
{
	buff_list *now;

	if (head)
	{
		while (*head)
		{
			now = *head;
			*head = (*head)->now;
			if (now->buff_ptr)
				free(now->buff_ptr);
			free(now);
		}
		*head = NULL;
	}
}

/**
 * add_buff - add node to the list
 * @pointer: old pointer to memory
 * @head: new head of the list
 * Return: pointer to the new list
 */

buff_list *add_buff(buff_list **head, char *pointer)
{
	buff_list *node_add;

	node_add = malloc(sizeof(buff_list));

	if (!node_add)
		return (NULL);

	add_node->buff_ptr = pointer;
	add_node->now = *head;
	*head = node_add;

	return (*head);
}

/**
 * buff_set - constant byte mem
 * @k: memory
 * @c: constant byte
 * @b: bytes
 * Return:  pointer to memory
 */

char *buff_set(char *k, char c, unsigned int b)
{
	unsigned int n = 0;

	while (n < c)
	{
		k[n] = c;
		n++;

	}
	return (k);


}
