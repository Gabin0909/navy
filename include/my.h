/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header
*/

#include "struct.h"

#ifndef MY_H
#define MY_H

int navy(int , char **);
void usage(void);
int error_handling(int);
char **create_map(void);
int navy(int, char **);
int file_error(int, char **);
int check_file(char ***);
int player_connection(int, char **);
char ***put_file_in_triple_array(char ***, int);
void load_maps(info_t *);
void game_loop(int, info_t *);

#endif
