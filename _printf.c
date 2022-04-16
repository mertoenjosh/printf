#include "main.h"

/**
 * print_int - prints integers
 * @args: list of arguments
 * @s: separator
 */

void print_int(va_list args, char *s)
{
	printf("%s%d", s, va_arg(args, int));
}

/**
 * print_float - prints floats
 *
 * @s: separator
 * @args: arguments
 */

void print_float(va_list args, char *s)
{
	printf("%s%f", s, va_arg(args, double));
}


/**
 * print_char - prints chars
 *
 * @args: arguments
 * @s: separator
 */

void print_char(va_list args, char *s)
{
	printf("%s%c", s, va_arg(args, int));
}

/**
 * print_str - prints strings
 *
 * @args: arguments
 * @s: separator
 */

void print_str(va_list args, char *s)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s%s", s, str);
}

/**
 * print_all - prints anything
 *
 * @format: a list of types of args passed
 */

void print_all(const char * const format, ...)
{
	va_list args;
	int i, j;
	char *s;

	type_t ops[] = {
		{"i", print_int},
		{"c", print_char},
		{"f", print_float},
		{"s", print_str},
		{NULL, NULL}
	};

	va_start(args, format);
	i = 0;
	s = "";
	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == *(ops[j]).op)
			{
				ops[j].f(args, s);
				s = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
