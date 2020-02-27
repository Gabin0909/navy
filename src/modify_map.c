/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** modify_map
*/

#include "my.h"
#include "lib.h"

void modify_player1_maps(info_t *info)
{
    int i = 0;
    int j = 0;

    for (; info->p1_map[0][j] != info->input[0]; j++);
    for (; info->p1_map[i][0] != info->input[1]; i++);
    if (info->p1_map[i][j] != '.') {
        info->atk = HIT;
        info->p1_map[i][j] = 'x';
    } else {
        info->atk = MISS;
        info->p1_map[i][j] = 'o';
    }
    i = 0;
    j = 0;
    for (; info->p1_enemy_map[0][j] != info->input[0]; j++);
    for (; info->p1_enemy_map[i][0] != info->input[1]; i++);
    if (info->atk == HIT)
        info->p1_enemy_map[i][j] = 'x';
    else
        info->p1_enemy_map[i][j] = 'o';
}

void modify_player2_maps(info_t *info)
{
    int i = 0;
    int j = 0;

    for (; info->p2_map[0][j] != info->input[0]; j++);
    for (; info->p2_map[i][0] != info->input[1]; i++);
    if (info->p2_map[i][j] != '.') {
        info->atk = HIT;
        info->p2_map[i][j] = 'x';
    } else {
        info->atk = MISS;
        info->p2_map[i][j] = 'o';
    }
    i = 0;
    j = 0;
    for (; info->p2_enemy_map[0][j] != info->input[0]; j++);
    for (; info->p2_enemy_map[i][0] != info->input[1]; i++);
    if (info->atk == HIT)
        info->p2_enemy_map[i][j] = 'x';
    else
        info->p2_enemy_map[i][j] = 'o';
}

void modify_maps(int ac, info_t *info)
{
    if (ac ==  2)
        modify_player1_maps(info);
    if (ac == 3)
        modify_player2_maps(info);
}
