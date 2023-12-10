#include "main.h"

size_t path_avail(char *const *arg);
size_t arg_len(char ptr_path);
size_t num_path(char *ar_path);

/**
 * arg_len - function taking available path length
 * @ptr_path: pointer to available path
 * Return: length of the available path
 */

size_t arg_len(char *ptr_path)
{
	size_t k = 0;

	if (ptr_path)
	{
		while (ptr_path[k] != ':' && ptr_path[k] != '\0')
		{
			k++;
		}
	}
	return (k);
}

/**
 * path_avail -function checking inclusion of path
 * @arg: argument of the command
 * Return: 1 if success, else 0
 */

size_t path_avail(char *const *arg)
{
	size_t nameOfpath = 0;
	size_t k = 0;

	for (arg[0][k]; k++)
	{
		if (arg[0][k] == '/')
		{
		nameOfpath = 1;
		break;
		}
	}
	return (nameOfpath);
}

/**
 * num_path - value of counted paths available
 * @ar_path: shows array of paths environment line
 * Return: number of path, else 0
 */

size_t num_path(char *ar_path)
{
	size_t k = 0;
	size_t val = 0;

	if (ar_path)
	{
		return (0);
	}
	while (ar_path[k])
	{
		if (ar_path[k + 1] == ':' || ar_path[k + 1] == '\0')
		{
			val++;
		}
		k++
	}
	return (val);
}
