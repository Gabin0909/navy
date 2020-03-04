/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_win.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

int check_win_map(int win, info_t *info)
{
    if (win == 14) {
        info->win_loose = WIN;
        return (1);
    }
    return (0);
}

int check_lose_map(int lose, info_t *info)
{
    if (lose == 14) {
        info->win_loose = LOOSE;
        return (1);
    }
    return (0);
}

int check_p1_win(info_t *info)
{
    int win = 0;
    int lose = 0;

    for (int i = 0; info->p1_map[i] != NULL; i++) {
        for (int j = 0; info->p1_map[i][j] != '\0'; j++) {
            if (info->p1_map[i][j] == 'x')
                lose++;
        }
    }
    if (check_lose_map(lose, info) != 0)
        return (1);
    for (int i = 0; info->p1_enemy_map[i] != NULL; i++) {
        for (int j = 0; info->p1_enemy_map[i][j] != '\0'; j++) {
            if (info->p1_enemy_map[i][j] == 'x') {
                win++;
            }
        }
    }
    if (check_win_map(win, info) != 0)
        return (1);
    return (0);
}

int check_p2_win(info_t *info)
{
    int win = 0;
    int lose = 0;

    for (int i = 0; info->p2_map[i] != NULL; i++) {
        for (int j = 0; info->p2_map[i][j] != '\0'; j++) {
            if (info->p2_map[i][j] == 'x')
                lose++;
        }
    }
    if (check_lose_map(lose, info) != 0)
        return (1);
    for (int i = 0; info->p2_enemy_map[i] != NULL; i++) {
        for (int j = 0; info->p2_enemy_map[i][j] != '\0'; j++) {
            if (info->p2_enemy_map[i][j] == 'x')
                win++;
        }
    }
    if (check_win_map(lose, info) != 0)
        return (1);
    return (0);
}
