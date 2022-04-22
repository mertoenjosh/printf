#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _vprintf(const char *format, va_list args);

/**
 * struct type - data type
 *
 * @op: data type argument
 * @f: function
 */

typedef struct type
{
	char *op;
	char *(*f)(va_list);
} type_t;

#ifndef __HELPERS__
#define __HELPERS__

int pos(const char *, int);
int _strlen(char *);
char *_strncat(char *, char *, int);
int _abs(int);
int num_len(int);
char *rev_string(char *);
char *utos(char str[], unsigned int);

#endif

#ifndef __DEPENDECIES__
#define __DEPENDECIES__

char *print_num(va_list);
char *print_str(va_list);
char *print_char(va_list);
char *print_bin(va_list);
char *print_oct(va_list);
char *print_p(va_list);
char *print_u(va_list);
char *print_h(va_list);
char *print_X(va_list);
char *print_lx(va_list);

#endif

#endif
