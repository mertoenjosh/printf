#include "main.h"

/**
 * print_oct - prints number with base 8
 *
 * @args: arguments passed
 * Return: character pointer
 */

char *print_oct(va_list args)
{
	unsigned int n;
	int i;
	char *oct;
	char *output;

	n = va_arg(args, int);
	oct = "0123456789ABCDEF";

	output = malloc(12 * sizeof(char));
	if (output == NULL)
		return (NULL);
	for (i = 0; n != 0; i++)
	{
		output[i] = oct[n % 8];
		n /= 8;
	}
	rev_string(output);

	return (output);
}

/**
 * print_p - function that print a pointer address
 *
 * @args: argument list
 * Return: character pointer
 */
char *print_p(va_list args)
{
	char *s = print_lx(args);

	return (s);
}

/**
 * print_lx - function that prints a long address
 *
 * @args: argument list
 * Return: charcter pointer
 */

char *print_lx(va_list args)
{
	unsigned long int num;
	int i;
	char *hex;
	char *output;
	void *a;

	a = va_arg(args, void *);
	if (a == NULL)
		return (NULL);

	num = (unsigned long int)a;
	hex = "0123456789abcdef";
	output = malloc(14 * sizeof(char));

	for (i = 0; num != 0; i++)
	{
		output[i] = hex[num % 16];
		num /= 16;
	}
	i += 2;
	output[13] = '0';
	output[12] = 'x';

	rev_string(output);
	return (output);
}

/**
 * print_u - print unsigned
 *
 * @args: arguments
 *
 * Return: character pointer
 */

char *print_u(va_list args)
{
	unsigned int num;
	int len;
	char *output;

	num = va_arg(args, int);
	len = num_len(num);
	output = malloc(len * sizeof(char));
	if (output == NULL)
		return (NULL);
	utos(output, num);
	return (output);
}


/**
 * print_h - prints hex
 * @args: arguments
 *
 * Return: char pointer
 */

char *print_h(va_list args)
{
	unsigned int n;
	int i;
	char *hex;
	char *output;

	n = va_arg(args, int);
	hex = "0123456789abcdef";
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
