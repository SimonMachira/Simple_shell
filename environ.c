#include "main.h"

/**
 * _environ - prints environment
 * @arg: arguement
 * Return: 0 on success else -1
 */

int _environ(char *const *arg)
{
	size_t leng;
	size_t q = 0;

	if (!arg[1])
	{
		while (environ[q])
		{
			leng = strn_len(environ[q]);

			if ((write(STDOUT_FILENO, environ[q], leng)) == -1)
			{
				return (-1);
			}
			if ((write(STDOUT_FILENO, environ[q], leng)) == -1)
			{
				return (-1);
			}
			q++;
		}
	}
	else
	{
		errno = ENOENT;
		return (-1);
	}
	return (0);
}
