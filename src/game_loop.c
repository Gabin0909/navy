/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_loop->c
*/

#include "lib.h"
#include "my.h"
#include "struct.h"
#include <stdlib.h>

void print_p1_turn(info_t *info)
{
    my_putstr("my_positions:\n");
    print_double_char(info->p1_map);
    my_putstr("\nenemy's positions:\n");
    print_double_char(info->p1_enemy_map);
    my_putchar('\n');
}

void print_p2_turn(info_t *info)
{
    my_putstr("my_positions:\n");
    print_double_char(info->p2_map);
    my_putstr("\nenemy's positions:\n");
    print_double_char(info->p2_enemy_map);
    my_putchar('\n');
}

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
