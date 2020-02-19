/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** print_players_turn
*/

#include <stdlib.h>
#include "lib.h"
#include "my.h"

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
