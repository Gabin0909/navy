/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** free_map
*/

#include <stdlib.h>

void free_double_char(char **map)
{
    int i = 0;

    if (map == NULL)
        return;
    for (; map[i] != NULL; i++)
        free(map[i]);
    free(map[i]);
    free(map);
    map = NULL;
}