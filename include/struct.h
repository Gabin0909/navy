/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** struct.h
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct info_s {
    char **p1_map;
    char **p1_enemy_map;
    char **p2_map;
    char **p2_enemy_map;
    int p1_win;
    int p2_win;
    char ***boat_pos;
}info_t;

#endif
