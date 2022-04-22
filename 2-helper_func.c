#include "main.h"

/**
 * pos - position of a string
 *
 * @s: string
 * @n: int
 * Return: int
 */

int pos(const char *s, int n)
{
	int i;

	i = 0;

	while (*s)
	{
		if (s[n + 1] != ' ')
			return (i);
		n++;
		i++;
	}
	return (0);
}

/**
 * utos - uint to string
 * @str: string
 * @num: num
 *
 * Return: char array
 */
char *utos(char str[], unsigned int num)
{
	int i, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	i = 0;

	while (i < len)
	{
		rem = num % 10;
		num = num / 10;

		str[len - (i + 1)] = rem + '0';
		i++;
	}

	str[len] = '\0';
	return (str);
}
