/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** already_hit.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

int already_hit(int argc, info_t *info)
{
    int i = 0;
    int j = 0;

    if (argc == 2) {
        for (; info->p1_enemy_map[0][j] != info->atk_pos[0]; j++);
        for (; info->p1_enemy_map[i][0] != info->atk_pos[1]; i++);
        if (info->p1_enemy_map[i][j] == 'x' || info->p1_enemy_map[i][j] == 'o')
            return (1);
    }
    else {
        for (; info->p2_enemy_map[0][j] != info->atk_pos[0]; j++);
        for (; info->p2_enemy_map[i][0] != info->atk_pos[1]; i++);
        if (info->p2_enemy_map[i][j] == 'x' || info->p1_enemy_map[i][j] == 'o')
            return (1);
    }
    return (0);
}
