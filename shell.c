#include "main.h"
#include "stdlib.h"
#include "unistd.h"

void rec_sig(int signal);

/**
 * rec_sig - re-display command line when [ctrl + c]
 * @signal: the attribute parameter
 */

void rec_sig(int signal __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n&", 3);
}

/**
 * main - point of entry
 * @argc: total sum of elements in argument array
 * @arg: the array of arguments
 * Return: 0 always
 */

int main(int argc __attribute__((unused)), char **arg)
{
	char **tokns = NULL;
	size_t buffsize = 1;
	char *mem = NULL;

	while (1)

	{
		tokns = NULL;
		mem = NULL;

		if (isatty(STDIN_FILENO))

			write(STDOUT_FILENO, "$$", 2);
		signal(SIGINT, rec_sig);

		if ((get_line(&mem)) == 0)
		{
			buff_free(&buff_head);
			free_stat_buff(&buff_stat_head);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		if (mem)
			tokns = strn_tokn(mem);

		if (tokns)
		{
			if ((exec_cmd(tokns)) == -1)
				err_print(buffsize, arg[0], tokns);
		}
		buff_free(&buff_head);

		buffsize++;
	}
	free_stat_buff(&buff_stat_head);
	return (0);
}
