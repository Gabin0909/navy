/*
** EPITECH PROJECT, 2019
** delivery_re
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char *str1, char *str2)
{
    int a = 0;
    int length1 = my_strlen(str1);
    int length2 = my_strlen(str2);
    int length_tot = length1 + length2;

    dest = malloc(sizeof(char) * (length_tot + 1));
    for (int i = 0; str1[i] != '\0'; i++, a++)
        dest[a] = str1[i];
    for (int i = 0; str2[i] != '\0'; i++, a++)
        dest[a] = str2[i];
    dest[a] = '\0';
    return (dest);
}