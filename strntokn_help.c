#include "main.h"

size_t tokn_ln(char *strn, size_t spec);
size_t tokn_cnt(char *strn);

/**
 * tokn_ln - function calculating amount of specific token
 * @strn: selected token string
 * @spec: displays specific token area
 * Return:ln
 */

size_t tokn_ln(char *strn, size_t spec)
{
	size_t ln = 0;
	size_t nw = 0;
	size_t curr = 0;

	while (curr < spec)
	{
		while (strn[nw] == ' ' || strn[nw] == '\t')
		{
			nw++;
		}
		if (strn[nw] != '\0' && strn[nw] != ' ' && strn[nw] != '\t')
		{
			curr++;
			while (strn[nw] != '\0' && strn[nw] != ' ' && strn[nw] != '\t')
			{
				if (curr == spec)
					ln++;
				nw++;
			}
		}
	}
	return (ln);
}

/**
 * tokn_cnt - a function for token summation
 * @strn: the string to sum up
 * Return: number of toksn
 */

size_t tokn_cnt(char *strn)
{
	size_t amnt = 0;
	size_t k = 0;

	while (strn[k] != '\0')
	{
		if (strn[k + 1] == ' ' || strn[k + 1] == '\t' || strn[m + 1] == '\0')
			amnt++;
		k++;
	}
	return (amnt);
}
