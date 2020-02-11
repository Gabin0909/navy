/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>

int search_flag(va_list arg, char *str, int i)
{
    switch (str[i]) {
        case 's': my_putstr(va_arg(arg, char *));
        break;
        case 'd':
        case 'i': my_put_nbr(va_arg(arg, int));
        break;
        case 'c': my_putchar(va_arg(arg, int));
        break;
        case 'o': my_put_nbr_base(va_arg(arg, int), "01234567");
        break;
        case 'x': my_put_nbr_base(va_arg(arg, int), "0123456789abcdef");
        break;
        case 'X': my_put_nbr_base(va_arg(arg, int), "0123456789ABCDEF");
        break;
        case 'u': my_put_nbr_base(va_arg(arg, int), "0123456789");
        break;
        case '%': my_putchar('%');
        break;
    }
    return (0);
}

int my_printf(char *str, ...)
{
    va_list arg;

    va_start(arg, str);
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == '%') {
            a++;
            for (; str[a] == ' '; a++);
            search_flag(arg, str, a);
        }
        else
            my_putchar(str[a]);
    }
    va_end(arg);
    return (0);
}