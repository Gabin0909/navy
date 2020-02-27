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
    while (info->win_loose != WIN && info->win_loose != LOOSE) {
        if (argc == 2) {
            print_p1_turn(info);
            if (do_attack(argc, info) != 0)
                return (84);
            wait_attack(info);
            modify_maps(argc, info);
        }
        if (argc == 3) {
            print_p2_turn(info);
            wait_attack(info);
            modify_maps(argc, info);
            if (do_attack(argc, info) != 0)
                return (84);
        }
    }
    return (0);
}
