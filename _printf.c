#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int len;

	va_start(arguments, format);

	if (format == NULL || arguments == NULL)
		return (-1);

	len = _vprintf(format, arguments);
	va_end(arguments);
	return (len);
}
