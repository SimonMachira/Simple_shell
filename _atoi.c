#include "main.h"

	char *_atoi(size_t num, char *buff, int tok);
	size_t digit_count(size_t digit);
	int _stoi(char *str);

/**
 * _stoi - converts a string to an int
 * @str: string to be converted to int
 * Return: str on success else -1
 */

int _stoi(char *str)
{
	int n = 0, result = 0;

	if (str[n] == '-')
	{
		return (-1);
	}
	for (; str[n] != '\0'; n++)
	{
		if (digit(str[n]))
		{
			result = result * 10 + str[n] - '0';
		}
		else
		{
		return (-1);
		}
	}
	if (result > 2147483647)
	{
	return (-1);
	}
	else
	{
	return (result);
	}
}
/**
 * digit_count - counts the digits in a number
 * @digit: digits to be counted
 * Return: number of digits
 */

size_t digit_count(size_t digit)
{
	size_t count = 0;

	for (; digit != 0; count++)
	{
		digit /= 10;
	}
	return (count);
}
/**
 * _atoi - converts numbers to strings
 * @num: number being converted
 * @buff: temporary storage for num
 * @tok: value
 * Return: String converted
 */

char *_atoi(size_t num, char *buff, int tok)
{
	size_t rem = 0;
	int n = 0;
	int isNegative = 1;

	if (num == 0)
	{
		buff[n++] = '\0';
		buff[n] = '\0';
	}
	while (num)
	{
		rem = num % tok;
		buff[n++] = '0' + rem;
		num /= tok;
	}
	if (isNegative < 0)
		buff[n] = '\0';
	return (_revstr(buff));

}
