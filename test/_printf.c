#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

void unsigned_num_to_str(uint64_t number, int base, char *buffer)
{
	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}

	char buf[65];
	for (int i = 0; i < 65; i++)
		buf[i] = 0;

	int cur = 0;

	while (number)
	{
		int digit = number % base;
		if (digit >= 10)
		{
			buf[cur++] = 'a' + (digit - 10);
		}
		else
		{
			buf[cur++] = '0' + digit;
		}

		number /= base;
	}

	for (int i = cur - 1; i != 0; i--)
		*buffer++ = buf[i];
	*buffer++ = buf[0];
	*buffer = 0;
}

void num_to_str(uint64_t number, int base, char *buffer)
{
	if ((int) number < 0)
	{
		*buffer++ = '-';
		number = (-number);
	}
	unsigned_num_to_str(number, base, buffer);
}

// 0: false
// 1: true

void _vprintf(const char *format, va_list args)
{
	int is_modulos = 0;
	int is_long = 0;
	int reset = 1;
	int num, i;
	int64_t _num;
	char buf[32];

	while (*format)
	{
		if (is_modulos == 0)
		{
			if (*format == '%')
				is_modulos = 1;
			else
				putchar(*format);
		} 
		else if (is_modulos == 1)
		{
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));  
					break;
				case 's':
					char *s = va_arg(args, char *);
					while (*s)
						putchar(*s++);
					break;
				case 'l':
					is_long = 1;
					reset = 0;
					break;

				case 'd':
					if (is_long == 1)
						_num = va_arg(args, long);
					else
						_num = va_arg(args, int);

					num_to_str(_num, 10, buf);
					for (i = 0; buf[i]; i++)
						putchar(buf[i]);
					break;
				case 'x':
					if (is_long == 1)
						_num = va_arg(args, unsigned long);
					else
						_num = va_arg(args, unsigned int);

					unsigned_num_to_str(_num, 16, buf);
					for (i = 0; buf[i]; i++)
						putchar(buf[i]);
					break;

				case 'p':
					putchar('0');
					putchar('x');
					void *n = va_arg(args, void *);
					unsigned_num_to_str((uint64_t) n, 16, buf);
					for (i = 0; buf[i]; i++)
						putchar(buf[i]);
					break;
			}
			if (reset == 1)
			{
				is_modulos = 0;
				is_long = 0;
			}
			else
				reset = 1;
		}
		format++;
	}
}

void _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	_vprintf(format, args);

	va_end(args);
}

int main()
{
	void *pointer_to_main = (void *) main;

	uint64_t n = (uint64_t) - 1;

	_printf("Print a character: %c %c. Done!\n", 'M', 'N');
	_printf("Print a string:%c %c %s. Done!\n", 'M', 'N', "Thuo");
	_printf("Print an integer: %d. Done!\n", 10);
	_printf("Print a neg integer: %d. Done!\n", -10);
	_printf("Print a hex integer: %x. Done!\n", 11);
	_printf("Print a zero hex int: %x. Done!\n", 0);
	_printf("Print a pointer: %p. Done!\n", pointer_to_main);
	_printf("Largest 64bit: %ld, %lx. Done!\n", n, n);

	return (0);
}
