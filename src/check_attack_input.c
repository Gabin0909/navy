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

int check_attack_input(char *atk_pos)
{
    if ((atk_pos[0] < 'A' || atk_pos[0] > 'Z')
    || (atk_pos[1] < '1' || atk_pos[1] > '8'))
        return (84);
    else if (my_strlen(atk_pos) != 2)
        return (84);
    return (0);
}
