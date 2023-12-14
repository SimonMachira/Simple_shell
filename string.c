#include "main.h"

size_t strn_len(const char *strng);
int str_comp(const char *strn1, const char *strn2);
int strn_compl(const char *strn1, const char *strn2, size_t q);

/**
 * strn_len - the function checking the length of string
 * @strng: the string whose length is under checked
 * Return: length of string,else 0 if not successful
 */

size_t strn_len(const char *strng)
{
	size_t leng = 0;

	if (strng != NULL)
	{
		while (*strng != '\0')
		{
			leng++;
			strng++;
		}
	}
	return (leng);
}

/**
 * str_comp - a two  string comparison function
 * @strn1: the string to compare first
 * @strn2: the string to compare second
 * Return: number
 */

int str_comp(const char *strn1, const char *strn2)
{
	int k = 0;

	while (strn1[k] != '\0' || strn2[k] != '\0')
	{
		if (strn1[k] < strn2[k])
			return (strn1[k] - strn2[k]);
		if (strn1[k] > strn2[k])
			return (strn1[k] - strn2[k]);
		k++;
	}
	return (0);
}

/**
 * strn_compl - a two string comparison function
 * @strn1: first string to compare
 * @strn2: second string to compare
 * @q: n=sum of strings to compare
 * Return: 0 always
 */

int strn_compl(const char *strn1, const char *strn2, size_t q)
{
	size_t k = 0;

	while (k < q && (strn1[k] != '\0' || strn2[k] != '\0'))
	{
		if (strn1[k] < strn2[k])
			return (strn1[k] - strn2[k]);
		if (strn1[k] > strn2[k])
			return (strn1[k] - strn2[k]);
		k++;
	}
	if (k < q && strn2[k] != '\0')
		return (strn1[k] - strn2[k]);
	return (0);
}
