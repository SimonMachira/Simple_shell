/*
 * File: shell.c
 * Author: Quinto Acquino, Simon Machira
 */

#include "main.h"
#include "stdlib.h"
#include "unistd.h"

void handle_interrupt(int signal);

/**
 * handle_interrupt - signal handler for SIGINT
 * @signal: unused attribute
 */

void handle_interrupt(int signal __attribute__((unused)))
{
	print(STDOUT_FILENO, "Simon&quinto$$", 14);
}

/**
 * main - point of entry
 * @argv: unused attribute
 * @argc: unused attribute
 * Return: 0 always
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char **tokens = NULL;
	size_t buffer_size = 1;
	char **input_buffer = NULL;

	while (1)

	{
		tokens = NULL;
		input_buffer = NULL;

		if (isatty(STDIN_FILENO))

			write(STDOUT_FILENO, "Simon&quinto$$", 14);
		signal(SIGINT, handle_interrupt);

		if ((read_user_input(&input_buffer)) == 0)

		{
			release_memory(&memory_head);
			release_stats_memory(&stat_mem_head);

			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		if (input_buffer)
			tokens = parse_input(input_buffer);

		if (tokens)
		{
			display_error_message(buffer_size);
		}

		release_memory(&memory_head);
		buffer_size++;
	}

	release_stats_memory(&stat_mem_head);

	return (0);
}
