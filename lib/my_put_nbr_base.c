/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_nbr_base
*/

#include "lib.h"

int	my_put_nbr_base(int nb, char *base)
{
    int	result;
    int	rest;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    result = nb / my_strlen(base);
    rest = nb % my_strlen(base);
    if (result > 0)
        my_put_nbr_base(result, base);
    my_putchar(base[rest]);
    return (0);
}