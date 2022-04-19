#include "main.h"
/**
 * _vprintf-prints out the arguements
 *
 * @format:lists the number of arguements in function prototype
 * @args:arguements found in function
 * Return:returns the number of character printed
 */

int _vprintf(const char *format, va_list args)
{
	int is_modulos = 0, len = 0, is_long = 0, reset = 1, i;
	char buf[32];
	void *n;

	while (format[len])
		len++;

	while (*format)
	{
		if (is_modulos == 0)
		{
			if (*format == '%')
				is_modulos = 1;
			else
				_putchar(*format);
		}
		else if (is_modulos == 1)
		{
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					--len;
					break;
				case 's':
					print_string(va_arg(args, char *));
					--len;
					break;
				case 'l':
					is_long = 1;
					reset = 0;
					--len;
					break;
				case 'd':
				case 'i':
					print_num(args, 10, is_long);
					--len;
					break;
				case 'u':
					print_unsigned_num(args, 10, is_long);
					--len;
					break;
				case 'x':
				case 'X':
					print_unsigned_num(args, 16, is_long);
					--len;
					break;
				case 'o':
					print_unsigned_num(args, 8, is_long);
					--len;
					break;
				case 'p':
					_putchar('0');
                     _putchar('x');
                   
					n = va_arg(args, void *);
                    unsigned_num_to_str((uint64_t) n, 16, buf);

					for (i = 0; buf[i]; i++)
                    	_putchar(buf[i]);
                    break;

				case '%':
					_putchar('%');
					--len;
					break;
				default:
					_putchar('%');
					_putchar(*format);
			}
			if (reset == 1)
			{
				is_modulos = 0;
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

/**
 * print_string - prints out strings
 *@s:pointer to a string character
 */
void print_string(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
}

/**
 *print_num - prints out the numbers
 *@base: base of a mumber
 *@is_long: a long interger
 *@args:function arguements
 */
void print_num(va_list args, int base, int is_long)
{
	int i;
	int64_t _num;
	char buf[32];

	_num = (is_long == 1) ? va_arg(args, long) :
		va_arg(args, int);

	num_to_str(_num, base, buf);
	for (i = 0; buf[i]; i++)
		_putchar(buf[i]);
}

/**
 *print_unsigned_num - prints unsigned numbers
 *@args: function arguements
 *@base:base of a number
 *@is_long:long interger
 */
void print_unsigned_num(va_list args, int base, int is_long)
{
	int i;
	int64_t _num;
	char buf[32];

	_num = (is_long == 1) ? va_arg(args, unsigned long) :
		va_arg(args, unsigned int);

	unsigned_num_to_str(_num, base, buf);
	for (i = 0; buf[i]; i++)
		_putchar(buf[i]);
}
