#include "main.h"

char *str_reverse(char *str);
char *cat_strn(char *app_str, const char *res_str);
char *copy_strnl(char *s1, const char *s2, size_t t);

/**
 * str_reverse - reverses a string
 * @str: strng to be reversed
 * Return: reversed string
 */

char *str_reverse(char *str)
{
	int b = 0;
	int c = 0;
	int length = 0;
	int val = 0;
	char buff;

	length = strn_len(str);

	if ((length % 2) == 0)
	{
		val = (length / 2);
	}
	else
		val = (length - 1) / 2;

	c = length - 1;
	while (b < val && c >= val)
	{
		buff = str[1];
		str[1] = str[c];
		str[c] = buff;
		b++;
		c--;
	}
	return (str);
}

/**
 * copy_strnl - copies s1 into s2
 * @s1: string one
 * @s2: the second string
 * @t: memory to be allocated
 * Return: s1
 */

char *copy_strnl(char *s1, const char *s2, size_t t)
{
	size_t k = 0;

	while (k < t && s2[k] != '\0')
	{
		s1[k]  = s2[k];
		k++;
	}
	while (k < t)
	{
		s1[k] = '\0';
		k++;
	}
	return (s1);
}

/**
 *cat_strn - combines two strings
 * @app_str: string where appending takes place
 * @res_str: appended string
 * Return: pointer to combined string
 */

char *cat_strn(char *app_str, const char *res_str)
{
	int k = 0;
	int t;

	while (app_str[k] != '\0')
	{
		k++;
	}
	for (t = 0; res_str[t] != '\0'; t++)
	{
		app_str[k] = res_str[t];
		k++;
	}
	app_str[m] = '\0';
	return (app_str);
}
