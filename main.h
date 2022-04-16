#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef __STRUCTS_H__
#define __STRUCTS_H__
/**
 * struct type - data type
 *
 * @op: data type argument
 * @f: function
 */

typedef struct type
{
	char *op;
	void (*f)(va_list, char *);
} type_t;

#endif

int _printf(const char *format, ...);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
