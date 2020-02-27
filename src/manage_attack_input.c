/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_attack_input.c
*/

#include <stdlib.h>
#include <stdio.h>
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

int do_attack(void)
{
    char *atk_pos = NULL;
    int *binary1 = NULL;
    int *binary2 = NULL;

    my_putstr("attack: ");
    atk_pos = get_next_line(0);
    if (atk_pos == NULL)
        return (84);
    if (check_attack_input(atk_pos) != 0) {
        my_putstr("wrong position\n");
        do_attack();
    }
    binary1 = my_getbinary(atk_pos[0], binary1);
    binary2 = my_getbinary(atk_pos[1], binary2);
    send_attack(binary1, atk_pos[0]);
    send_attack(binary2, atk_pos[1]);
    return (0);
}

int check_attack_input(char *atk_pos)
{
    if ((atk_pos[0] < 'A' || atk_pos[0] > 'H')
    || (atk_pos[1] < '1' || atk_pos[1] > '8'))
        return (84);
    else if (my_strlen(atk_pos) != 2)
        return (84);
    return (0);
}
