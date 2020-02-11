/*
** EPITECH PROJECT, 2018
** jkldsd
** File description:
** djkls
*/

#include <stdlib.h>

int my_str_isnum(char const *str)
{
    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}