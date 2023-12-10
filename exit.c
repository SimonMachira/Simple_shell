/*
 * File: exit.c
 * Author: Acquino Quinto, Simon Machira
 */

#include "main.h"
#include <stdlib.h>

/**
 * is_number - check character is is a digit
 * @c: character to check
 *
 * Return: 1 if character is a digit, else 0
 */
int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * exiting - terminate shell with optional exit status
 * @argue: cmd-line arguments
 *
 * Return: EXIT_SUCCESS on success, else EXIT_FAILURE
 */
int exiting(char *const *argue)
{
	int exit_status;

	if (argue[1] == NULL)
	{
		free_stat_memory(&stat_mem_head);
		free_memory(&memory_head);
		exit(EXIT_SUCCESS);
	}
	else
	{
		exit_status = _atoi(argue[1]);

		switch (exit_status)
		{
			case -1:
				return (EXIT_FAILURE);
			default:
				free_stat_memory(&stat_mem_head);
				free_memory(&memory_head);
				exit(exit_status);
		}
	}
}
