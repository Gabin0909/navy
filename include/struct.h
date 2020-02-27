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
    int win_loose;
    int atk;
    char *input;
    int p1_pid;
    int *p2_binary;
    char ***boat_pos;
}info_t;

typedef struct global_s {
    int enemy_pid;
}global_t;

#endif
