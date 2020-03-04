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

void check_win_map(int win, info_t *info)
{
    if (win == 14) {
        info->win_loose = WIN;
        my_printf("I won\n");
    }
}

void check_lose_map(int lose, info_t *info)
{
    if (lose == 14) {
        info->win_loose = LOOSE;
        my_printf("Enemy won\n");
    }
}

void check_p1_win(info_t *info)
{
    int win = 0;
    int lose = 0;

    for (int i = 0; info->p1_map[i] != NULL; i++) {
        for (int j = 0; info->p1_map[i][j] != '\0'; j++) {
            if (info->p1_map[i][j] == 'x')
                lose++;
        }
    }
    check_lose_map(lose, info);
    for (int i = 0; info->p1_enemy_map[i] != NULL; i++) {
        for (int j = 0; info->p1_enemy_map[i][j] != '\0'; j++) {
            if (info->p1_enemy_map[i][j] == 'x') {
                win++;
            }
        }
    }
    check_win_map(win, info);
}

void check_p2_win(info_t *info)
{
    int win = 0;
    int lose = 0;

    for (int i = 0; info->p2_map[i] != NULL; i++) {
        for (int j = 0; info->p2_map[i][j] != '\0'; j++) {
            if (info->p2_map[i][j] == 'x')
                lose++;
        }
    }
    check_lose_map(lose, info);
    for (int i = 0; info->p2_enemy_map[i] != NULL; i++) {
        for (int j = 0; info->p2_enemy_map[i][j] != '\0'; j++) {
            if (info->p2_enemy_map[i][j] == 'x')
                win++;
        }
    }
    check_win_map(lose, info);
}

void check_win(int argc, info_t *info)
{
    if (argc == 2)
        check_p1_win(info);
    if (argc == 3)
        check_p2_win(info);
}
