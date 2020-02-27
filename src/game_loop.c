/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_loop->c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

int game_loop(int argc, info_t *info)
{
    char *coord = NULL;

    if (argc == 2) {
        print_turn(info);
        if (do_attack() != 0)
            return (84);
    }
    while (info->win_loose != WIN && info->win_loose != LOOSE) {
        print_turn(info);
        wait_attack();
        do_attack();
    }
    return (0);
}
