/*
** EPITECH PROJECT, 2019
** delivery_re
** File description:
** my_str_isalpha
*/
#include <stdlib.h>

int my_str_isnumalpha(char const *str)
{
    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z')
        && (str[i] < 'a' || str[i] > 'z')
        && (str[i] < '0' || str[i] > '9'))
            return (1);
    }
    return (0);
}