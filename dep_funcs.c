#include "main.h"

/**
 * print_char - prints characters
 *
 * @args: arguments passed
 * Return: char pointer
 */

char *print_char(va_list args)
{
	static char ch[2] = {0, '\0'};

	ch[0] = va_arg(args, int);
	if (ch[0] == '\0')
		return (" ");
	return (ch);
}

/**
 * print_str - prints strings
 *
 * @args: argument passed
 * Return: char pointer
 */

char *print_str(va_list args)
{
	char *s;

	s = va_arg(args, char *);
	if (s == NULL)
		return (s = "(null)");
	return (s);
}

/**
 * print_num - prints signed and unsigned nums
 *
 * @args: arguments passed
 * Return: char pointer
 */

char *print_num(va_list args)
{
	int val = 0, i = 0, neg = 0;
	int div = 1000000000;
	char *output;
	int num = va_arg(args, int);
	int len = num_len(num);

	output = malloc(len * sizeof(char) + 1 + neg);

	if (output == NULL)
	{
		free(output);
		return (0);
	}

	if (num < 0)
	{
		neg++;
	}

	if (num < 0)
	{
		output[i] = '-';
		i++;
	}

	if (num > -10 && num < 10)
	{
		output[i] = _abs(num) + '0';
		return (output);
	}

	while (div)
	{
		val = (num / div) % 10;
		if (num < 0)
		{
			val = _abs(val);
		}
		if (val != 0 || (len >= 0  && output[i - 1] >= '0'))
		{
			output[i] = val + '0';
			i++;
			len--;
		}
		div /= 10;
	}
	output[i] = '\0';
	return (output);
}

