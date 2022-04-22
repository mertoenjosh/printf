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

