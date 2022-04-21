#ifndef __MAIN_H__
#define __MAIN_H__

#define TRUE 1
#define FALSE 0

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct type - data type
 *
 * @op: data type argument
 * @f: function
 */

typedef struct type
{
        char *op;
        void (*f)(va_list, int);
} type_t;

int _putchar(char c);
int _printf(const char *format, ...);
int _vprintf(const char *format, va_list args);
void num_to_str(uint64_t number, int base, char *buffer);
void unsigned_num_to_str(uint64_t number, int base, char *buffer);
void print_string(char *);
void print_num(va_list, int, int);
void print_unsigned_num(va_list, int, int);

#endif
