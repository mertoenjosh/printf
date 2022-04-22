#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int print_str(va_list, char *, unsigned int);
int _printf(const char *format, ...);
int _vprintf(const char *format, va_list);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_chr(va_list, char *, unsigned int);
int print_(va_list, char *, unsigned int);
int print_int(va_list, char *, unsigned int);
int print_oct(va_list, char *, unsigned int);
int print_unt(va_list, char *, unsigned int);
int prinlunt(va_list, char *, unsigned int);
int print_hex(va_list, char *, unsigned int);
int print_upx(va_list, char *, unsigned int);
int print_usr(va_list, char *, unsigned int);
int print_rev(va_list, char *, unsigned int);
int prinlint(va_list, char *, unsigned int);
int print_add(va_list, char *, unsigned int);
int print_rot(va_list, char *, unsigned int);
int prinloct(va_list, char *, unsigned int);
int prinnoct(va_list, char *, unsigned int);
int prinlupx(va_list, char *, unsigned int);
int prinhint(va_list, char *, unsigned int);
int prinhunt(va_list, char *, unsigned int);
int prinhoct(va_list, char *, unsigned int);
int prinhhex(va_list, char *, unsigned int);
int prinhupx(va_list, char *, unsigned int);
int prinpint(va_list, char *, unsigned int);
int prinsint(va_list, char *, unsigned int);
int prinnhex(va_list, char *, unsigned int);
int prinnupx(va_list, char *, unsigned int);
int ev_print_func(const char *, int);
int (*get_print_func(const char *, int))(va_list, char *, unsigned int);
int prinlhex(va_list, char *, unsigned int);
unsigned int handl_buf(char *, char c, unsigned int);
int print_buf(char *, unsigned int);
char *fill_binary_array(char *, long int, int, int);
char *fill_oct_array(char *, char *);
char *fill_long_oct_array(char *, char *);
char *fill_short_oct_array(char *, char *);
char *fill_hex_array(char *, char *, int, int);

#endif

