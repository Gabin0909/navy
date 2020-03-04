/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_loop->c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

global_t global;

int p1_turn(int argc, info_t *info)
{
    print_p1_turn(info);
    if (do_attack(argc, info) != 0)
        return (84);
    my_printf("%s:  ", info->atk_pos);
    check_attack();
    wait_attack(argc, info);
    modify_maps(argc, info);
    free(info->atk_pos);
    return (0);
}

int p2_turn(int argc, info_t *info)
{
    print_p2_turn(info);
    wait_attack(argc, info);
    modify_maps(argc, info);
    if (do_attack(argc, info) != 0)
        return (84);
    my_printf("%s:  ", info->atk_pos);
    check_attack();
    free(info->atk_pos);
    return (0);
}

int game_loop(int argc, info_t *info)
{
    while (info->win_loose != WIN && info->win_loose != LOOSE) {
        if (argc == 2) {
            if (p1_turn(argc, info) != 0)
                return (84);
        }
        if (argc == 3) {
            if (p2_turn(argc, info) != 0)
                return (84);
        }
    }
    return (0);
}
