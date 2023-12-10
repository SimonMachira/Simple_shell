#include "main.h"

/**
 * isDigit - checks whether it is a number
 * @str: argument being checked
 * Return: 1 on success else 0
 */

int isDigit(char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * terminate - exits the shell
 * @arg: current status
 * Return: exit else FAIL
 */

int terminate(char *const *arg)
{
	int result;

	if (arg[1] == NULL)
	{
		free_buff(&buff_head);
		free_stat_buff(&buff_stat_head);
		exit(EXIT_SUCCESS);
	}
	else
	{
	result = _stoi(arg[]);

	switch (result)
	{
		case (-1):
			return (EXIT_FAILURE);
		default:
			free_buff(&buff_head);
			free_stat_buff(&buff_stat_head);
			exit(result);
	}
	}
}
