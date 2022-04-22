#include "main.h"
/**
 * unsigned_num_to_str - converts number to string
 * @number : number converted to string
 * @base : base number of a numbers
 * @buffer : reserved space
 */
void unsigned_num_to_str(uint64_t number, int base, char *buffer)
{
	char buf[65];
	int cur = 0;
	int i = 0;

	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}
	for (i = 0; i < 65; i++)
		buf[i] = 0;

	while (number)
	{
		int digit = number % base;

		if (digit >= 10)
			buf[cur++] = 'a' + (digit - 10);
		else
			buf[cur++] = '0' + digit;
		number /= base;
	}

	for (i = cur - 1; i != 0; i--)
		*buffer++ = buf[i];
	*buffer++ = buf[0];
	*buffer = 0;
}

/**
 * num_to_str - converts number to string
 * @number : number converted to string
 * @base : base number of a numbers
 * @buffer : reserved space
 */
void num_to_str(uint64_t number, int base, char *buffer)
{
	if ((int) number < 0)
	{
		*buffer++ = '-';
		number = (-number);
	}
	unsigned_num_to_str(number, base, buffer);
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
void format_s(va_list args, char *buf, int *index)
{
	int i, j;
	char *s;

	s = va_arg(args, char*);
	if (s == NULL)
		s = "(null)";
	for (i = *index, j = 0; s[j] != '\0';  *index += 1, i++, j++)
	{
		if (*index == 1024)
		{
			_write_buffer(buffer, index);
			reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = s[j];
	}
}

