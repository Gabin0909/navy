/*
** EPITECH PROJECT, 2019
** delivery_re
** File description:
** my_strncmp
*/

#include <stdio.h>

int my_strncmp(char *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return (0);
    for (; i < n - 1 && s1[i] == s2[i] && s2[i] && s1[i]; i++);
    return (s1[i] - s2[i]);
}