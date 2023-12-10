/*
 * File: env.c
 * Authors: Acquino, Simon Machira
 */

#include "main.h"
#include <errno.h>

/**
 * print_env - print environment variables
 * @argue: cmd arguments (unused in implementation)
 *
 * Return: 0 if successful, else -1
 */
int print_env(char *const *argue)
{
	size_t m = 0;

	if (!argue[1])
	{
		while (environ[m])
		{
			size_t length = _strlen(environ[m]);

			if (write(STDOUT_FILENO, environ[m], length) == -1)
			{

				return (-1);
			}
			m++;
		}
	}
	else
	{
		errno = ENOENT;

		return (-1);
	}

	return (0);
}
