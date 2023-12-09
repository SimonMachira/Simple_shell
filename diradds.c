#include "main.h"

/**
 * environ_var - creates copy of environment
 * @environ_n: environment variable
 * Return: Success path else NULL
 */

char *environ_var(char *environ_n)
{
	size_t path_len = 0;
	size_t env_len = 0;
	size_t k = 0;
	char *path_size = NULL;

	for (environ[k]; k++)
	{
		if ((strn_compl(environ_n, environ[j], env_len)) == 0)
		{
			path_len = (strn_len(environ[k]) - env_len);
			path_size = mal_alloc(path_size, (sizeof(char) * (path_len + 1)));
			if (!path_size)
			{
			return (NULL);
			}
			copy_strl(path_size, &environ[k][env_len], path_len);
			return (path_size);
		}
	}
	errno = ENOENT;
	return (NULL);
}

/**
 * cd_wd - changes current working directory
 * @dir_path: directory path
 * Return: 0 on success else 1
 */

int cd_wd(char *dir_path)
{
	size_t leng = 0;
	char *path_size = NULL;
	char *dir_val = NULL;

	if (chdir(dir_path) == 0)
	{
		if (path_exists(&dir_path))
		{
			oldPWD_set();
			PWD_set(dir_path);
			return (0);
		}
		else
		{
		dir_val = var_get("PWD = ");
		leng = (strn_len(dir_val) + strn_len(dir_path));
		path_size = mal_alloc(path_size, (sizeof(char) * (leng + 2)));
		if (!path_size)
		{
			return (-1);
		}
		copy_strnl(path_size, dir_val, strn_len(dir_val));
		cat_strn(path_size, "/");
		cat_strn(path_size, dir_path);
		oldPWD_set();
		PWD_set(dir_val);

		return (0);
		}
	}
	errno = ENOENT;
	return (-1);
}

/**
 * cd_before - changes to the directory that was there before
 * Return: 0 on success else 1
 */

int cd_before(void)
{
	char *dir_val = NULL;

	dir_val = var_get("old PWD = ");

	if (dir_val)
	{
	if (chdir(dir_val) == 0)
	{
		oldPWD_set();
		PWD_set(dir_val);

		write(STDOUT_FILENO, dir_val, (_strn_len(dir_val)));
		write(STDOUT_FILENO, "n", 1);
		return (0);
	}
	else
		return (-1);
	}
	return (-1);
}
