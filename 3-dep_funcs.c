#include "main.h"

/**
 * print_X - princt hex with capital
 * @args: arguments
 *
 * Return: character pointer
 */

char *print_X(va_list args)
{
	unsigned int n;
	int i;
	char *hex;
	char *output;

	n = va_arg(args, int);
	hex = "0123456789ABCDEF";
	output = malloc(9 * sizeof(char));
	if (output == NULL)
		return (NULL);
	for (i = 0; n != 0; i++)
	{
		output[i] = hex[n % 16];
		n /= 16;
	}
	rev_string(output);
	return (output);
}

/**
 * print_bin - print binary
 * @list: va_list
 * Return: pointer to string of binary
 */

char *print_bin(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);
	char s[1024];
	char *b;
	int i;

	b = s;
	i = 0;

	if (n == 0)
	{
		s[++i] = '0';
	}

	while (n != 0)
	{
		s[i] = (n % 2) + '0';
		i++;
		n /= 2;
	}

	rev_string(s);
	s[i] = '\0';

	return (b);
}
