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
        if (boat[i][0][0] > '5' || boat[i][0][0] < '2') {
            my_putstr("Wrong boat length.\n");
            return (1);
        }
        total += my_atoi(boat[i][0]);
    }
    if (total != 14) {
        my_putstr("File can not contain twot times the same boat length.\n");
        return (1);
    }
    return (0);
}

int check_miss_arg_split(char ***boat)
{
    int b = 0;

    for (int j = 0; boat[j] != NULL; j++) {
        for (; boat[j][b] != NULL; b++);
        if (b != 3) {
            my_putstr("Wrong arguments.\n");
            return (1);
        }
        b = 0;
    }
    return (0);
}

int check_wrong_arg_value(char ***boat, int i)
{
    for (int j = 1; boat[i][j] != NULL; j++) {
        if (my_strlen(boat[i][j]) != 2) {
            my_putstr("Too many arguments on boats parameters.\n");
            return (1);
        }
        for (int b = 0; boat[i][j][b] != '\0'; b++) {
            if (boat[i][j][0] < 'A' || boat[i][j][0] > 'H') {
                my_putstr("Wrong arguments.\n");
                return (1);
            }
            if (boat[i][j][1] < '0' || boat[i][j][1] > '9') {
                my_putstr("Wrong arguments.\n");
                return (1);
            }
        }
    }
    return (0);
}

int check_file(char ***boat)
{
    int i = 0;

    for (; boat[i] != NULL; i++);
    if (i != 4) {
        my_putstr("Not enough boats.\n");
        return (1);
    }
    if (check_miss_arg_split(boat) != 0)
        return (1);
    if (check_boat_length(boat) != 0)
        return (1);
    for (int j = 0; boat[j] != NULL; j++) {
        if (check_wrong_arg_value(boat, j) != 0)
            return (1);
    }
    return (0);
}
