/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** free_triple_array
*/

#include "lib.h"
#include <stdlib.h>

void free_triple_array(char ***array)
{
    int i = 0;

    for (; array[i] != NULL; i++)
        free_double_char(array[i]);
    free_double_char(array[i]);
    free(array);
}