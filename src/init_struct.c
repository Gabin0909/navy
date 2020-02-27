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
    info->win_loose = 0;
    info->p1_pid = 0;
    info->map = NULL;
    info->enemy_map = 0;
    info->boat_pos = NULL;
}
