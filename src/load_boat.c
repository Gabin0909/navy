/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** load_boat.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include "lib.h"
#include "struct.h"
#include "my.h"

void put_boats_in_map(info_t *info, char **str, int i)
{
    char x1 = info->boat_pos[i][1][0];
    char y1 = info->boat_pos[i][1][1];
    char x2 = info->boat_pos[i][2][0];
    char y2 = info->boat_pos[i][2][1];
    int xboat = 0;
    int yboat = my_atoi_simpl(y1) + 1;
    int j = 0;

    if (y1 == y2) {
        for (; str[0][xboat] != x1; xboat++);
        for (; str[j][0] != y1; j++);
        for (int length = xboat + (i + 2) * 2; xboat < length; xboat += 2)
            str[j][xboat] = my_itoa(i + 2)[0];
    }
    else if (x1 == x2) {
        for (; str[0][j] != x1; j++);
        for (int length = yboat + i + 2; yboat < length; yboat++)
            str[yboat][j] = my_itoa(i + 2)[0];
    }
}

void load_boat(int argc, info_t *info)
{
    int i = 0;

    if (argc == 2) {
        for (; info->boat_pos[i] != NULL; i++)
            put_boats_in_map(info, info->p1_map, i);
    } else if (argc == 3) {
        for (; info->boat_pos[i] != NULL; i++)
            put_boats_in_map(info, info->p2_map, i);
    }
}

int check_boats_p1(info_t *info)
{
    int b = 0;

    for (int i = 0; info->p1_map[i] != NULL; i++) {
        for (int j = 0; info->p1_map[i][j] != '\0'; j++) {
            if (info->p1_map[i][j] == '2' || info->p1_map[i][j] == '3'
            || info->p1_map[i][j] == '4' || info->p1_map[i][j] == '5')
                b++;
        }
    }
    if (b != 18) {
        free_all(info);
        return (1);
    }
    return (0);
}

int check_boats_p2(info_t *info)
{
    int b = 0;

    for (int i = 0; info->p2_map[i] != NULL; i++) {
        for (int j = 0; info->p2_map[i][j] != '\0'; j++) {
            if (info->p2_map[i][j] == '2' || info->p2_map[i][j] == '3'
            || info->p2_map[i][j] == '4' || info->p2_map[i][j] == '5')
                b++;
        }
    }
    if (b != 18) {
        free_all(info);
        return (1);
    }
    return (0);
}

int check_boats(int ac, info_t *info)
{
    if (ac == 2)
        return (check_boats_p1(info));
    else if (ac == 3)
        return (check_boats_p2(info));
    return (0);
}