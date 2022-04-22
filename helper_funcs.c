#include "main.h"

/**
 * _strlen - length of a string
 *
 * @s: the string
 * Return: int
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strncat - concatenates n bytes of a string to another
 *
 * @dest: destination
 * @src: source
 * @n: number of bytes
 *
 * Return: character pointer
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[n + i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _abs - returns absolute value of a number
 *
 * @n: int
 * Return: int
 */

int _abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
/**
 * num_len - calculates length of a number
 *
 * @n: integer
 * Return: length
 */

int num_len(int n)
{
	int len = 0;

	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/**
 * rev_string - reverses a string
 *
 * @s: string to reverse
 * Return: void
 */

char *rev_string(char *s)
{
	int i = 0;
	int aux = 0;
	char ltemp;

	while (*(s + i) != '\0')
		i += 1;
	i -= 1;

	while (aux < i)
	{
		ltemp = s[i];
		s[i] = s[aux];
		s[aux] = ltemp;
		aux++;
		i--;
	}
	return (s);
}

