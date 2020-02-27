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

global_t global;

int navy(int argc, char **argv)
{
    info_t info;

    init_struct(&info);
    if (usage(argc, argv) != 0)
        return (1);
    if (error_handling(argc) != 0)
        return (84);
    if (file_error(argc, argv, &info) != 0)
        return (84);
    if (player_connection(argc, argv) != 0)
        return (84);
    load_maps(&info);
    load_boat(argc, &info);
    if (game_loop(argc, &info) != 0)
        return (84);
    free_all(&info);
    return (0);
}
