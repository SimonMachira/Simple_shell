#include "main.h"

int buff_alloc(char *buf);
void buff_shft(char *buf, ssize_t q);
ssize_t get_line(char **mem);
ssize_t buff_cp(char **app_str, char *res_str, ssize_t *start);

/**
 * buff_cp - function copying buffer till '\0'
 * @app_str: destination for copied
 * @res_str: source to be copied
 * @start: line alreay copied
 * Return: 0 always
 */

ssize_t buff_cp(char **app_str, char *res_str, ssize_t *start)
{
	ssize_t val_cp = 0;
	ssize_t k;

	for (k = 0; res_str[k] != '\n' && res_str[k] != '\0'; k++)
		val_cp++;
	if (res_str[k] == '\n')
	{
		*app_str = mal_alloc(*app_str, (sizeof(char) * (val_cp + *start + 1)));
		if (!(*app_str))
			return (-1);
		copy_strnl((*app_str + *start), res_str, val_cp);
		buff_shft(res_str, (val_cp + 1));
		return (val_cp);
	}
	if (res_str[k] == '\0')
	{
		*app_str = mal_alloc(*app_str, (sizeof(char) * (val_cp + *start + 1)));
		if (!(*app_str))
			return (1);
		copy_strnl((*app_str + *start), res_str, (val_cp));
		*start = *start + val_cp;
		return (val_cp);
	}
	return (val_cp);
}

/**
 * buff_alloc - a buffer comparison function if empty
 * @buf: allocated memory to test
 * Return:the written bytes in memory
 */

int buff_alloc(char *buf)
{
	int bytz = 0;

	while (buf[bytz])
	{
		bytz++;
	}
	return (bytz);
}

/**
 * buff_shft - function reallocating buffer to the left
 * @buf: memory allocated to shift
 * @q: num of bytz for allocated memory to shift
 */

void buff_shft(char *buf, ssize_t q)
{
	ssize_t k = 0;

	while (buf[q] != '\0')
	{
		buf[k] = buf[q];
		k++;
		q++;
	}
	buff_set(&buf[k], 0, (1024 - q));
}


/**
 * get_line - function for retrieving command line
 * @mem: store area for command line
 * Return: 0 always
 */


ssize_t get_line(char **mem)
{
	ssize_t cp = 0, val = 0;
	ssize_t start = 0;
	static char ln[total_args];
	static ssize_t tot;

	if ((buff_alloc(ln)) == 0)
	{
		while ((val = read(STDIN_FILENO, ln, total_args - 1)) > 0)
		{
			if (val == -1)
				return (-1);
			tot = tot + val;
			ln[val] = '\0';
			cp = buff_cp(&(*mem), ln, &start);
			if (cp < val)
			{
				start = 0;
				return (tot);
			}
		}
		tot = 0;
	}
	else
	{
		cp = (buff_cp(&(*mem), ln, &start) + 1);
	}
	return (tot);
}
