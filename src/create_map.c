/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** create_map.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

char **map_fill(char **map)
{
    map[0] = " |A B C D E F G H";
    map[1] = "-+---------------";
    map[2] = "1|. . . . . . . .";
    map[3] = "2|. . . . . . . .";
    map[4] = "3|. . . . . . . .";
    map[5] = "4|. . . . . . . .";
    map[6] = "5|. . . . . . . .";
    map[7] = "6|. . . . . . . .";
    map[8] = "7|. . . . . . . .";
    map[9] = "8|. . . . . . . .";
    return (map);
}

char **malloc_empty_map(char **map)
{
    int i = 0;

    map = malloc(sizeof(char *) * 11);
    for (; i <= 9; i++) {
        map[i] = malloc(sizeof(char) * 20);
        map[i][18] = '\n';
        map[i][19] = '\0';
    }
    map[10] = NULL;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j < 18; j++)
            map[i][j] = 0;
    }
    return (map);
}

char **create_map(void)
{
    char **map = NULL;

    map = malloc_empty_map(map);
    map = map_fill(map);
    return (map);
}
