#include "main.h"

/**
 * _printf - handles the  conversion specifiers c ,s ,%
 *
 * @format: const character string
 * Return: length of of characters
 */
int _printf(const char *format, ...)
{
	int len = 0;

	va_list args;

	va_start(args, format);

	if (format == NULL || args == NULL)
		return (-1);

	len = _vprintf(format, args);
	va_end(args);
	return (len);
}
