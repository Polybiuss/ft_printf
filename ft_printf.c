#include "ft_printf.h"
#include<stdio.h>
#include<unistd.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;

    va_start(args, format);
        while (format[i])
        {
            if (format[i] == '%' && format[i + 1] == 'a')
                write(1, va_arg(args, char *), 3);
            else
                write(1, &format[i], 1);
            ++i;
        }
            // printf("%s\n", format);
            // printf("%s", va_arg(args, char *));
    va_end(args);
    return (0);
}

int main(void)
{
    ft_printf("ceci %a un %a", "est", "test");
    return (0);
}