/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_loop->c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

void wait_attack(void)
{
    my_putstr("waiting for enemy's attack...\n");
    pause();
}

void do_attack(void)
{
    my_putstr("attack: ");
    get_next_line(0);
}

void game_loop(int argc, info_t *info)
{
    while (info->p1_win == 0 && info->p2_win == 0) {
        if (argc == 2) {
            print_p1_turn(info);
            do_attack();
        }
        else if (argc == 3) {
            print_p2_turn(info);
            wait_attack();
        }
        info->p1_win = 1;
    }
}
