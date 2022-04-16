#include "main.h"

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

