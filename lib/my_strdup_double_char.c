/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_strdup_double_char
*/

#include <stdlib.h>
#include "lib.h"

char **my_strdup_double_char(char **dest, char **src)
{
    int i = 0;
    int a = 0;

    for (; src[i] != NULL; i++);
    dest = malloc(sizeof(char *) * (i + 1));
    for (; src[a] != NULL; a++)
        dest[a] = malloc(sizeof(char) * my_strlen(src[a]) + 1);
    dest[a] = NULL;
    dest = my_strcpy_double_char(dest, src);
    return (dest);
}