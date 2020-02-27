/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** print_players_turn
*/

#include <stdlib.h>
#include "lib.h"
#include "my.h"

void print_turn(info_t *info)
{
    my_putstr("my_positions:\n");
    print_double_char(info->map);
    my_putstr("\nenemy's positions:\n");
    print_double_char(info->enemy_map);
    my_putchar('\n');
}
