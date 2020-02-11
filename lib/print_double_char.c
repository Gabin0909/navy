/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** print_double_char
*/

#include <stdlib.h>
#include "my.h"

void print_double_char(char **d_str)
{
    for (int i = 0; d_str[i] != NULL; i++) {
        my_putstr(d_str[i]);
        my_putchar('\n');
    }
}