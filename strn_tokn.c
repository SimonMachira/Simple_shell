#include "main.h"

char **strn_tokn(char *tokn);

/**
 * strn_tokn - function that tokenizes a string
 * @tokn: string to tokenize
 * Return: pointer to first element of array
 */

char **strn_tokn(char *tokn)
{
	size_t amnt, msiz;
	char **toks = NULL;
	size_t ln = 0, curr = 1;
	size_t k = 0, lineSet = 0, tok_cpy = 0;

	amnt = tokn_cnt(tok);
	if (amnt == 0)
	{
		return (NULL);
	}
	msiz = (amnt + 1) * (sizeof(char *));
	toks = (char **) mg_alloc((char *)toks, msiz);
	if (toks == NULL)
		return (NULL);
	while (curr <= amnt)
	{
		ln = tokn_ln(tokn, curr);
		msiz = (ln + 1) * (sizeof(char));
		if (toks[k] == NULL)
		{
			return (NULL);
		}
		while (tokn[lineSet] == '' || tokn[lineSet] == '\t')
			lineSet++;
		while (tokcpy < ln)
		{
			token[k][tokcpy] = tokn[lineSet];
			tokcpy++;
			lineSet++;
		}
		toks[k][tokcpy] = '\0';
		curr++;
		k++;
	}
	toks[k] = NULL;
	return (toks);
}