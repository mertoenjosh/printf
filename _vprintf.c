#include "main.h"

/**
 * _vprintf - does the actual printinf of the buffer to stdout
 *
 * @format: string to replace the specifiers
 * @args: arguments to replace the specifiers
 *
 * Return: length of the string to print
 */

int _vprintf(const char *format, va_list args)
{
	int j, i;
	int len = 0;
	char *buffer;
	char *s;

	type_t type[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_num},
		{"d", print_num},
		{"b", print_bin},
		{"o", print_oct},
		{"p", print_p},
		{"u", print_u},
		{"x", print_h},
		{"X", print_X},
		{NULL, NULL}
	};

	buffer = malloc(1024 * sizeof(char));

	if (!buffer)
	{
		free(buffer);
		return (-1);
	}

	if (format == NULL || args == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == '%')
			continue;
		else if (format[i] == '%')
		{
			if (format[i + 1] == ' ')
				i += pos(format, i);
			for (j = 0; type[j].f != NULL; j++)
			{
				if (format[i + 1] == *(type[j].op))
				{
					s = type[j].f(args);
					if (s == NULL)
						return (-1);
					_strlen(s);
					_strncat(buffer, s, len);
					len += _strlen(s);
					i++;
					break;
				}
			}
			if (type[j].f == NULL)
			{
				buffer[len] = format[i];
				len++;
			}
		}
		else
		{
			buffer[len] = format[i];
			len++;
		}
	}

	buffer[len] = '\0';
	write(1, buffer, len);
	free(buffer);
	return (len);
}
