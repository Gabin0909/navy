/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** modify_map
*/

#include <stdlib.h>
#include "my.h"
#include "lib.h"

void modify_ennemy_map(info_t *info, char **str)
{
    int i = 0;
    int j = 0;

    for (; str[0][j] != info->input[0]; j++);
    for (; str[i][0] != info->input[1]; i++);
    if (info->atk == HIT)
        str[i][j] = 'x';
    else
        str[i][j] = 'o';
}

void modify_player_map(info_t *info, char **str)
{
    int i = 0;
    int j = 0;

    for (; str[0][j] != info->input[0]; j++);
    for (; str[i][0] != info->input[1]; i++);
    if (str[i][j] != '.') {
        info->atk = HIT;
        str[i][j] = 'x';
    } else {
        info->atk = MISS;
        str[i][j] = 'o';
    }
}

void modify_maps(int ac, info_t *info)
{
    if (info->input == NULL)
        return;
    if (ac == 2) {
        modify_ennemy_map(info, info->p1_enemy_map);
        modify_player_map(info, info->p1_map);
    } else if (ac == 3) {
        modify_ennemy_map(info, info->p2_enemy_map);
        modify_player_map(info, info->p2_map);
    }


}
