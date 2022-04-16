#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int main(void)
{
	_printf("sj", "sksks", "gsgs");
	return (0);
}

int _printf(const char *format, ...)
{
	char **str;
	int i = 0;
	va_list args;

	va_start(args, format);
	
	while (format[i])
	{
		str = va_arg(args, char**);
		printf("%s ", str);
		i++;
	}
	va_end(args);
	return (0);
}
