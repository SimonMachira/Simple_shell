#include "main.h"

/**
 * cd_dir - used to change dir
 * @arg: argument
 * Return: 0 on success else 1
 */

int cd_dir(char *const *arg)
{
	if (arg[1] == NULL || !(strn_compl(arg[1], "~")))
	{
	if (cd_home())
		return (-1);
	}
	else if (!(str_comp(arg[1], ".")))
	{
		if (cd_current())
			return (-1);
	}
	else if (!(str_comp(arg[1], "..")))
	{
		if (cd_prnt())
			return (-1);
	}
	else if (!(str_comp(arg[1], "-")))
	{
		if (cd_before())
			return (-1);
	}
	else if ((!(strn_compl(arg[1], "~", 1)) && (arg[1][1] != '\0')))
	{
		if (cd_user(arg[1]))
			return (-1);
	}
	else
	{
		if (cd_wd(arg[1]))
			return (-1);
	}
	return (0);
}

/**
 * cd_home - change to home directory
 * Return: 0 on success else -1
 */

int cd_home(void)
{
	char *dir_val = NULL;

	dir_val = var_get("Home = ");

	if (dir_val)
	{
		if (chdir(dir_val) == 0)
		{
			oldPWD_set();
			PWD_set(dir_val);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}

/**
 * cd_current - change current directory
 * Return: 0 on success else -1
 */

int cd_current(void)
{
	char *dir_val = NULL;

	dir_val = var_get("PWD = ");

	if (dir_val)
	{
		if (chdir(dir_val) == 0)
		{
			oldPWD_set();
			PWD_set(dir_val);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}

/**
 * cd_prnt - change to parent
 * Return: 0 on success else -1
 */

int cd_prnt(void)
{
	char *dir_val = NULL;
	size_t k;

	dir_val = var_get("PWD = ");

	if (dir_val)
	{
		for (k = strn_len(dir_val); dir_val[k] != '/';)
			k--;
		for (; dir_val[k]; k++)
			dir_val[k] = '\0';

		if (chdir(dir_val) == 0)
		{
			oldPWD_set();
			PWD_set(dir_val);
			return  (0);
		}
	}
	return (-1);
}

/**
 * cd_user - change to user
 * @arg: user
 * Return: 0 on success else 1
 */

int cd_user(char *arg)
{
	char *user_path = NULL;
	size_t name_len = strn_len(arg);

	user_path = mal_alloc(user_path, (sizeof(char) * (6 + name_len)));
	if (!user_path)
		return (-1);
	copy_strnl(user_path, "/home/", 6);
	cat_strn(user_path, &arg[1]);

	if (chdir(user_path) == 0)
	{
		oldPWD_set();
		PWD_set(user_path);
		return (0);
	}
	errno = ENOENT;
	return (-1);
}
