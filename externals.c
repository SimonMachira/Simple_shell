#include "main.h"

/**
 * ext_command - executes external commands
 * @arg: command passed
 * Return: 0 on success else -1
 */

int ext_command(char *const *arg)
{
	char **array_p = NULL;
	int status, k;
	pid_t pid;

	if (path_avail(arg))
	{
		array_p = (char **)mal_alloc((char *)array_p, (sizeof(char *) * 2));
		array_p[0] = mal_alloc(array_p[0], (sizeof(char) * (strn_len(arg[0]) + 1)));
		copy_strnl(array_p[0], arg[0], strn_len(arg[0]));
	array_p[1] = NULL;
	}
	else
		array_p = gen_path(arg);

	for (k = 0; array_p[k]; k++)
		if (access(array_p[k], (R_OK | X_OK)) == 0)
		{
			switch ((pid = fork()))
			{
				case -1:
					return (-1);
				case 0:
					execve(array_p[k], arg, environ);
					msg_err = 1;

					exit(EXIT_FAILURE);
				default:
					if ((waitpid(pid, &status, 0)) == -1)
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

	for (k = 0; builtin_cmd[k].command; k++)
		if ((str_comp(arg[0], builtin_cmd[k].command)) == 0)
		{
			cmd_func_ptr = builtin_cmd[k].pr;

			if ((cmd_func_ptr(arg)) == 0)
				return (0);

			msg_err = 3;
			return (-1);

		}
	msg_err = 2;
	return (-1);


}
