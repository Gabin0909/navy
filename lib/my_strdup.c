/*
** EPITECH PROJECT, 2019
** delivery_re
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *dest, char const *src)
{
    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    my_strcpy(dest, src);
    return (dest);
}