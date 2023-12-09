#include "main.h"

/**
 * gen_err - prints an error
 * @ptr2: stores error message
 * @token: token
 * Return: NULL
 */

char *gen_err(char *ptr2, char **token)
{
	size_t token1 = strn_len(token[0]);
	size_t token2 = strn_len(token[1]);

	if (token1 == 4)
	{
		ptr2 = mal_alloc(ptr2, (sizeof(char) * 10));
		ptr2 = ": Error: \0";
		return (ptr2);
	}
	else if (token1 == 2)
	{
		ptr2 = mal_alloc(ptr2, (sizeof(char) * 9));
		ptr2 = ": Error: \0";
		return (ptr2);
	}

	ptr2 = mal_alloc(ptr2, sizeof(char) * token1 + token2 + 5);

	copy_strnl(ptr2, token[0], token1);
	cat_strn(ptr2, ": ");
	cat_strn(ptr2, token[1]);
	cat_strn(ptr2, " ");

	errno = ENOENT;

	perror(ptr2);

	return (NULL);
}
