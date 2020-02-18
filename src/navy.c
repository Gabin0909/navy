/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include <stdio.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

void init_struct(info_t *info)
{
    info->p1_enemy_map = NULL;
    info->p1_map = NULL;
    info->p2_enemy_map = NULL;
    info->p2_map = NULL;
}

int navy(int argc, char **argv)
{
    info_t info;

    if (usage(argc, argv) != 0)
        return (1);
    if (error_handling(argc) == 84)
        return (84);
    init_struct(&info);
    load_maps(&info);
    if (file_error(argc, argv) != 0)
        return (84);
    if (player_connection(argc, argv) != 0)
        return (84);
    game_loop(argc, &info);
    return (0);
}
