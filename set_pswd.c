#include "main.h"

/**
 * oldPWD_set - sets path value of oldPWD var
 *
 * Return: 0 if success, else 0
 */

int oldPWD_set(void)
{
	size_t k;
	char *upd_val = NULL;
	char *pswd_ref = "PSWD=";
	char prev_ref = "OLDPSWD=";
	size_t pswd_sz = 0;
	char *pswd = NULL;

	for (k = 0; environ[k]; k++)
	{
		if ((strn_compl(pswd_ref, environ[k], 4)) == 0)
			pswd = &environ[k][4];
	}
	if (!pswd)
		return (-1);

	pswd_sz = strn_len(pswd);

	k = 0;
	while (environ[k])
	{
		if ((strn_compl(prev_ref, environ[k], 7)) == 0)
		{
		environ[k] = new_alloc(upd_val, (sizeof(char) * (7 + pswd_sz + 1)));
		if (!environ[k])
			return (-1);
		new_buff(&buff_stat_head, environ[k]);

		copy_strnl(environ[j], prev_ref, 7);
		cat_strn(environ[k], pswd);

		return (0);
		}
		k++;
	}
	errno = ENOENT;
	return (-1);
}

/**
 * PWD_set - update and update PWD environment variable
 * @var_v: the value of given variable
 *
 * Return: 0 if succesfull, otherwise 1
 */

int PWD_set(char *var_v)
{
	size_t n = 0;
	char *upd_val = NULL;
	size_t *vnum_len;
	size_t title_sz = 4;
	char title = "PSWD";

	vnum_len = strn_len(var_v);

	n = 0;
	while (environ[n])
	{
		if ((strn_compl(title, environ[n], title_sz)) == 0)
		{
			environ[n] = new_alloc(upd_val, (sizeof(char) * (title_sz + vnum_len + 1)));
			if (!environ[n])
				return (-1);

			new_buff(&buff_stat_head, environ[n]);
			copy_strnl(environ[n], title, title_sz);
			cat_strn(environ[n], var_v);

			if (environ[n][title_sz + var_v - 1] == '/')
			{
				environ[n][title_sz + var_v - 1] = '\0';
			}
			return (0);
		}
		n++;
	}
	errno = ENOENT;
	return (-1);
}
