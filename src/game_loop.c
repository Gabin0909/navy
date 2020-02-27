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

global_t global;

void wait_attack(void)
{
    my_putstr("waiting for enemy's attack...\n");
    for (int i = 0; i != 13; i++) {
        receive_attack();
    }
}

void do_attack(void)
{
    char *atk_pos = NULL;
    int *binary1 = NULL;
    int *binary2 = NULL;

    my_putstr("attack: ");
    atk_pos = get_next_line(0);
    if (atk_pos == NULL) {
        my_putstr("\nattack: ");
        do_attack();
    }
    if (check_attack_input(atk_pos) != 0) {
        my_putstr("wrong position\n");
        do_attack();
    }
    binary1 = my_getbinary(atk_pos[0], binary1);
    binary2 = my_getbinary(atk_pos[1], binary2);
    send_attack(binary1, atk_pos[0]);
    send_attack(binary2, atk_pos[1]);
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
