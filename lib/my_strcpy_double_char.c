/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_strcpy_double_char
*/

#include <stdlib.h>
#include "my.h"

char **my_strcpy_double_char(char **dest, char **src)
{
    int i = 0;

    for (; src[i] != NULL; i++)
        dest[i] = my_strcpy(dest[i], src[i]);
    dest[i] = NULL;
    return (dest);
}