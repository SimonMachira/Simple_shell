#include "main.h"

char **gen_path(char *const *arg);

/**
 * gen_path - function that generates path
 * @arg: command
 * Return: array of pointers
 */

char **gen_path(char *const *arg)
{
	size_t k = 0, val, env = 0;
	char **ar_path = NULL;
	char *name = "PATH=";
	size_t buff_size;
	char *ptr_path = NULL;

	while (environ[env])
	{
		if (strn_compl(name, environ[env], 5) == 0)
		{
			ptr_path = &environ[env][5];
			val = num_path(ptr_path);
			ar_path = (char **)mal_alloc((char *)ar_path, (sizeof(char *) * (val + 1)));
			while (k < arr_path)
			{
				buff_size = (len_way(ptr_path) + strn_len(arg[0]) + 2);
				ar_path[m] = mal_alloc(ar_path[k], (sizeof(char) * buff_size));
				copy_strnl(ar_path[k], ptr_path, arg_len(ptr_path));
				cat_strn(ar_path[k], "/");
				cat_strn(ar_path[k], arg[0]);

				ptr_path = (ptr_path = (arg_len(ptr_path) = 1));
				k++;
			}
			ar_path[k] = NULL;
			return (ar_path);
		}
		env++;
	}
	return (NULL);
}
