/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** init_struct
*/

#include <stdlib.h>
#include "struct.h"

void init_struct(info_t *info)
{
    info->p1_win = 0;
    info->p2_win = 0;
    info->p1_enemy_map = NULL;
    info->p1_map = NULL;
    info->p2_enemy_map = NULL;
    info->p2_map = NULL;
    info->boat_pos = NULL;
}
