#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _vprintf(const char *format, va_list args);
void num_to_str(uint64_t number, int base, char *buffer);
void unsigned_num_to_str(uint64_t number, int base, char *buffer);
void print_string(char *s);

#endif
