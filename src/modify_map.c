/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** modify_map
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "lib.h"

global_t global;

void check_hit_p1(info_t *info)
{
    if (info->atk == HIT) {
        my_printf("hit\n\n");
    }
    else {
        my_printf("missed\n\n");
    }
}

void check_hit_p2(info_t *info)
{
    if (info->atk == HIT) {
        my_printf("hit\n\n");
    }
    else {
        my_printf("missed\n\n");
    }
}

void modify_enemy_maps(info_t *info, char **str)
{
    int i = 0;
    int j = 0;

    info->atk = global.var;
    for (; str[0][j] != info->atk_pos[0]; j++);
    for (; str[i][0] != info->atk_pos[1]; i++);
    if (info->atk == HIT) {
        str[i][j] = 'x';
    }
    else
        str[i][j] = 'o';
}

void modify_player_map(info_t *info, char **str, int pid)
{
    int i = 0;
    int j = 0;

    for (; str[0][j] != info->input[0]; j++);
    for (; str[i][0] != info->input[1]; i++);
    if (str[i][j] != '.') {
        info->atk = HIT;
        str[i][j] = 'x';
        usleep(4000);
        kill(pid, SIGUSR1);
    } else {
        info->atk = MISS;
        str[i][j] = 'o';
        usleep(4000);
        kill(pid, SIGUSR2);
    }
}

void modify_maps(int ac, info_t *info)
{
    if (info->input == NULL)
        return;
    if (ac == 2) {
        modify_player_map(info, info->p1_map, info->enemy_pid);
        check_hit_p1(info);
    } else if (ac == 3) {
        modify_player_map(info, info->p2_map, info->p1_pid);
        check_hit_p2(info);
    }
}
