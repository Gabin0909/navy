/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** struct.h
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct info_s {
    char **map;
    char **enemy_map;
    int win_loose;
    int p1_pid;
    char ***boat_pos;
}info_t;

typedef struct global_s {
    int enemy_pid;
}global_t;

#endif
