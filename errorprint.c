#include "main.h"

/**
 * err_print - prints error message
 * @rpt: loops
 * @arg: shell name
 * @token: token with error message
 */

void err_print(size_t rpt, char *arg, char **token)
{
	size_t token_length = strn_len(token[0]), token_length2 = strn_len(token[1]);
	size_t arg_len = strn_len(arg);
	char *ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL;
	size_t ptr2_len, ptr1_len;
	size_t num = num_count(rpt);
	size_t mem_sum = arg_len + num + token_length + token_length2 + 6;

	switch (msg_err)
	{
		case (2):
			ptr2 = mal_alloc(ptr2, (sizeof(char) * 8));
			ptr2 = ": fail\0";
			break;
		case (3):
			ptr2 = gen_err(ptr2, token);
			if (ptr2 == NULL)
				return;
			break;
		default:
			perror(arg);
			return;
	}
	ptr3 = mal_alloc(ptr3, (sizeof(char) * (num + 1)));
	_atoi(rpt, ptr2, 10);
	ptr2_len = strn_len(ptr2);
	mem_sum += ptr2_len;
	ptr1 = mal_alloc(pyr1, sizeof(char) * mem_sum);
	copy_strnl(ptr1, arg, arg_len);
	cat_strn(ptr1, ": ");
	cat_strn(ptr1, ptr2);
	cat_strn(ptr1, ": ");
	cat_strn(ptr1, token[0]);
	cat_strn(ptr1, ptr2);
	if (msg_err == 3)
		cat_strn(ptr1, token[0]);
	cat_strn(ptr1, "\n");
	ptr1_len = strn_len(ptr1);
	write(STDERR_FILENO, ptr1, ptr1_len);
}
