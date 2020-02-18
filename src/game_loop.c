/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_loop->c
*/

#include <stdlib.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

void game_loop(int argc, info_t *info)
{
    while (info->p1_win == 0 && info->p2_win == 0) {
        if (argc == 2) {
            print_p1_turn(info);
        }
        else if (argc == 3) {
            print_p2_turn(info);
        }
        info->p1_win = 1;
    }
}
