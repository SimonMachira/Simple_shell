#include "main.h"

/**
 * ext_command - executes external commands
 * @arg: command passed
 * Return: 0 on success else -1
 */

int ext_command(char *const *arg)
{
	char **array_path = NULL;
	int condition, k;
	pid_t pid;

	if (path_exists(arg))
	{
		array_path = (char **)mal_alloc((char *)path_ar, (sizeof(char *) * 2));
		array_path[0] = mal_alloc(array_path[0], (sizeof(char) * (strn_len(arg[0]) + 1)));
		copy_strnl(array_path[0], arg[0], strn_len(arg[0]));
	array_path[1] = NULL;
	}
	else
		array_path = get_path(arg);

	for (k = 0; array_path[j]; j++)
		if (access(array_path[k], (R_OK | X_OK)) == 0)
		{
			switch ((pid = fork()))
			{
				case -1:
					return (-1);
				case 0:
					execve(array_path[k], arg, environ);
					msg_err = 1;

					exit(EXIT_FAILURE);
				default:
					if ((waitpid(pid, &condition, 0)) == -1)
						return (-1);
					else
						return (0);
			}
		}
	msg_err = 2;
	return (-1);
}

/**
 * process_builtin - executes external commands
 * @arg: arguement passed
 * Return: 0 on success else 1
 */

int process_builtin(char *const *arg)
{
	shell_cmd builtin_cmd[] = {
		{"exit", terminate},
		{"env", environ},
		{"cd", cd_dir},
		{NULL, NULL}
	};

	int k;
	int (*cmd_func_ptr)(char *const *arg);

	for (k = 0; builtin_cmd[k].cmd; k++)
		if ((str_comp(arg[0], builtin_cmd[k].cmd)) == 0
		{
			cmd_func_ptr = builtin_cmd[k].fp;

			if ((cmd_func_ptr(arg) == 0)
				return (0);

			msg_err = 3;
			return (-1);

		}
	msg_err = 2;
	return (-1);


}
