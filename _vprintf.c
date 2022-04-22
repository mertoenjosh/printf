#include "main.h"

/**
 * print_int - prints integers
 * @args: list of arguments
 * @s: separator
 */

void print_int(va_list args, int is_long)
{
	char buf[32];
	int64_t _num;
	int i;

	_num = (is_long == 1) ? va_arg(args, long) :
		va_arg(args, int);

	num_to_str(_num, 10, buf);
	for (i = 0; buf[i]; i++)
		_putchar(buf[i]);
}

/**
 * print_char - prints chars
 *
 * @args: arguments
 * @s: separator
 */

void print_char(va_list args, int is_long __attribute__((unused)))
{
        _putchar(va_arg(args, int));
}

/**
 * print_str - prints strings
 *
 * @args: arguments
 * @s: separator
 */

void print_str(va_list args,  int is_long __attribute__((unused)))
{
        char *str = va_arg(args, char *);
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}

/**
 * get_op_func - gets operation to perfom
 *
 * @s: op passed by user as arg
 *
 * Return: result of operation
 */

int (*get_op_func(char *s))(int, int)
{
}

/**
 * _vprintf-prints out the arguements
 *
 * @format:lists the number of arguements in function prototype
 * @args:arguements found in function
 * Return:returns the number of character printed
 */

int _vprintk(const char *format, va_list args)
{
	int j, len = 0, is_modulos =  0, is_long = 0, found = 0, reset = 1;
	int64_t _num;
	char buf[32];

	type_t type[] = {
                {"c", print_char},
                {"s", print_str},
		{"d", print_int},
		{"i", print_int},
                {NULL, NULL}
        };

	while (format[len])
		len++;

	while (*format)
	{	
		if (is_modulos == 0 )
		{
			if (*format == '%')
				is_modulos = 1;

			else
				_putchar(*format);
		}
		else if	(is_modulos == 1)
		{
			j = 0;
			while (j < 5 && found == 0)
			{
				if (*format == *(type[j]).op)
				{
					type[j].f(args, is_long);
					found = 1;
					--len;
				}
				else if (*format == '%')
				{
					_putchar('%');
					found = 1;
					--len;
				}
				else
				{
					_putchar('%');
					_putchar(*format);
					found = 1;
				}
				j++;
			}

			if (reset == 1)
                        {
                                is_modulos = 0;
				found = 0;
                                is_long = 0;
                        }
                        else
                        {
                                reset = 1;
                        }
		}
		format++;
	}
	return (len);
}
