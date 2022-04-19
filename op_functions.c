#include "main.h"

void unsigned_num_to_str(uint64_t number, int base, char *buffer)
{
	char buf[65];
	int cur = 0;

	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}
	for (int i = 0; i < 65; i++)
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
