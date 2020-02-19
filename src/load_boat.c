/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** load_boat.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include "lib.h"
#include "struct.h"
#include "my.h"

void first_player_boats(info_t *info, int i)
{
    char x1 = info->boat_pos[i][1][0];
    char y1 = info->boat_pos[i][1][1];
    char x2 = info->boat_pos[i][2][0];
    char y2 = info->boat_pos[i][2][1];
    int xboat = 0;
    int yboat = my_atoi_simpl(y1) + 1;
    int j = 0;

    if (y1 == y2) {
        for (; info->p1_map[0][xboat] != x1; xboat++);
        for (; info->p1_map[j][0] != y1; j++);
        for (int length = xboat + (i + 2) * 2; xboat < length; xboat += 2)
            info->p1_map[j][xboat] = my_itoa(i + 2)[0];
    }
    else if (x1 == x2) {
        for (; info->p1_map[0][j] != x1; j++);
        for (int length = yboat + i + 2; yboat < length; yboat++)
            info->p1_map[yboat][j] = my_itoa(i + 2)[0];
    }
}

void second_player_boats(info_t *info, int i)
{
    char x1 = info->boat_pos[i][1][0];
    char y1 = info->boat_pos[i][1][1];
    char x2 = info->boat_pos[i][2][0];
    char y2 = info->boat_pos[i][2][1];
    int xboat = 0;
    int yboat = my_atoi_simpl(y1) + 1;
    int j = 0;

    if (y1 == y2) {
        for (; info->p2_map[0][xboat] != x1; xboat++);
        for (; info->p2_map[j][0] != y1; j++);
        for (int length = xboat + (i + 2) * 2; xboat < length; xboat += 2)
            info->p2_map[j][xboat] = my_itoa(i + 2)[0];
    }
    else if (x1 == x2) {
        for (; info->p2_map[0][j] != x1; j++);
        for (int length = yboat + i + 2; yboat < length; yboat++)
            info->p2_map[yboat][j] = my_itoa(i + 2)[0];
    }
}

void load_boat(int argc, info_t *info)
{
    int i = 0;

    if (argc == 2)
        for (; info->boat_pos[i] != NULL; i++)
            first_player_boats(info, i);
    else if (argc == 3) {
        for (; info->boat_pos[i] != NULL; i++)
            second_player_boats(info, i);
    }
}
