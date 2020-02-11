/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** task02
*/

#include "my.h"

int my_putstr(char const *str)
{
    int z = 0;

    while (str[z] != '\0') {
        my_putchar(str[z]);
        z++;
    }
    return (0);
}
