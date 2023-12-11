#include "main.h"

/**
 * prnt_env - an environment printing function
 * @arg: the argument cmd
 * Return: 0 if succesful, else -1
 */

int prnt_env(char *const *arg)
{
	size_t leng;
	size_t k = 0;

	if (!arg[1])
	{
		while (environ[k])
		{
			leng = strn_len(environ[k]);

			if ((write(STDOUT_FILENO, environ[k], leng)) == -1)
			{
				return (-1);
			}

			if ((write(STDOUT_FILENO, environ[k], leng)) == -1)
			{
				return (-1);
			}
			k++;
		}
	}
	else
	{
		errno = ENOENT;
		return (-1);
	}
	return (0);
}
