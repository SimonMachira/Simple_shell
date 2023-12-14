#include "shell.h"


/**
 * bfree - a funct to free pointer and NULLs the address
 *
 *
 * @ptr: the pointer address to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
