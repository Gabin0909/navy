/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** check_file
*/

#include <stdlib.h>
#include "lib.h"

int check_boat_length(char ***boat)
{
    int total = 0;

    for (int i = 0; boat[i] != NULL; i++) {
        if (boat[i][0][0] > '5' || boat[i][0][0] < '2')
            return (1);
        total += my_atoi(boat[i][0]);
    }
    if (total != 14)
        return (1);
    return (0);
}

int check_file(char ***boat)
{
    int i = 0;
    int b = 0;

    for (; boat[i] != NULL; i++);
    if (i != 4)
        return (1);
    for (int j = 0; boat[j] != NULL; j++) {
        for (; boat[j][b] != NULL; b++);
        if (b != 3)
            return (1);
        b = 0;
    }
    if (check_boat_length(boat) != 0)
        return (1);
    return (0);
}
