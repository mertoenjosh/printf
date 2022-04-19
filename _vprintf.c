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
	int is_modulos = 0;
	int len = 0;
	int is_long = 0;
	int reset = 1;
	int num, i;
	int64_t _num;
	char buf[32];

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
					char ch = va_arg(args, int);

					_putchar(ch);
					--len;
					break;
				case 's':
					char *s = va_arg(args, char *);

					print_string(s);
					--len;
					break;
				case 'l':
					is_long = 1;
					reset = 0;
					--len;
					break;
				case 'd':
				case 'i':
					_num = (is_long == 1) ? va_arg(args, long) : va_arg(args, int);

					num_to_str(_num, 10, buf);
					for (i = 0; buf[i]; i++)
						_putchar(buf[i]);
					--len;
					break;
				case 'u':
					_num = (is_long == 1) ? va_arg(args, unsigned long) : va_arg(args, unsigned int);

					unsigned_num_to_str(_num, 10, buf);
					for (i = 0; buf[i]; i++)
						_putchar(buf[i]);
					--len;
					break;
				case 'x':
				case 'X':
					_num = (is_long == 1) ? va_arg(args, unsigned long) : va_arg(args, unsigned int);

					unsigned_num_to_str(_num, 16, buf);
					for (i = 0; buf[i]; i++)
						_putchar(buf[i]);
					--len;
					break;
				case 'o':
					_num = (is_long == 1) ? va_arg(args, unsigned long) : va_arg(args, unsigned int);

					unsigned_num_to_str(_num, 8, buf);
					for (i = 0; buf[i]; i++)
						_putchar(buf[i]);
					--len;
					break;
				case 'p':
					_putchar('0');
					_putchar('x');
					void *n = va_arg(args, void *);

					unsigned_num_to_str((uint64_t) n, 16, buf);
					for (i = 0; buf[i]; i++)
						_putchar(buf[i]);
					--len;
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
 * 
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
 * print_int - prints out intergers
 * 
 */
void print_int(int i)
{
}
