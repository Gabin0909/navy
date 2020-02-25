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

void wait_attack(void)
{
    my_putstr("waiting for enemy's attack...\n");
    pause();
}

void do_attack(void)
{
    char *atk_pos = NULL;
    int *binary = 0;

    my_putstr("attack: ");
    atk_pos = get_next_line(0);
    if (check_attack_input(atk_pos) != 0)
        do_attack();
    binary = my_getbinary(atk_pos[0], binary);
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
