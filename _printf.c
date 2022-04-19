#include "main.h"

int _printf(const char *format, ...)
{
	int len = 0;

	va_list args;

	va_start(args, format);

	len = _vprintf(format, args);

	va_end(args);

	return (len);
}
