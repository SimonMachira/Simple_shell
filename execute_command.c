#include "main.h"

/**
 * exec_cmd - executes the commands
 * @arg: arguements passed
 *Return: 0 on success else -1
 */

int exec_cmd(char *const *arg)
{
	int value;

	value = process_builtin(arg);
	if (value == 0)
		return (0);

	if (msg_err == 2)
	{
		value = (ext_command(arg));
		if (value == 0)
		{
			return (0);
		}
	}
	return (-1);
}
