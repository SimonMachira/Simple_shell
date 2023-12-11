#include "main.h"
#include "stdlib.h"
#include "unistd.h"

void rec_sig(int sign);

/**
 * rec_sig - re-display command line when [ctrl + c]
 * @sign: the attribute parameter
 */

void rec_sig(int sign __attribute__((unused)))
{
	print(STDOUT_FILENO, "\n$$", 3);
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
	char **mem = NULL;

	while (1)

	{
		tokns = NULL;
		mem = NULL;

		if (isatty(STDIN_FILENO))

			write(STDOUT_FILENO, "$$", 2);
		sign(SIGINT, rec_sig);

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
			if ((func_cmd(tokns)) == -1)
				prnt_err(buffsize, arg[0], tokns);
		}
		buff_free(&buff_head);

		buffsize++;
	}
	free_stat_buff(&free_stat_buff);
	return (0);
}
