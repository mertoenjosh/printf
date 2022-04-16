#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int _printf(const char *format, ...);
void _vprintf(const char *format, va_list args);
void num_to_str(uint64_t number, int base, char *buffer);
void unsigned_num_to_str(uint64_t number, int base, char *buffer);

#endif
