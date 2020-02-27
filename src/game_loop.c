/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_loop->c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

global_t global;

int game_loop(int argc, info_t *info)
{
    info->enemy_pid = global.var;

    if (argc == 2) {
        print_turn(info);
        do_attack();
        wait_attack();
    }
    while (info->win_loose != WIN && info->win_loose != LOOSE) {
        print_turn(info);
        wait_attack();
        do_attack();
    }
}
