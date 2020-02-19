/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_itoa
*/
#include "my.h"
#include <stdlib.h>

char *my_itoa(int nb)
{
    int length = 0;
    char *str = NULL;
    int tmp = nb;

    for (; tmp > 0; length++)
        tmp /= 10;
    str = malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length + 1; i++)
        str[i] = '\0';
    for(; length > 0; length--) {
        str[length - 1] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}