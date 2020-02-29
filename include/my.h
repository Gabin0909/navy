/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header
*/

#include "struct.h"
#include "macro.h"

#ifndef MY_H
#define MY_H

int navy(int , char **);
int usage(int argc, char **argv);
int error_handling(int);
char **create_map(void);
int navy(int, char **);
int file_error(int ac, char **av, info_t *info);
int check_file(char ***);
int player_connection(int, char **, info_t *);
void load_maps(info_t *);
int game_loop(int, info_t *);
void print_p1_turn(info_t *info);
void print_p2_turn(info_t *info);
char ***put_file_in_triple_array(char ***boat_pos, int fd);
void init_struct(info_t *info);
void load_boat(int argc, info_t *info);
void free_all(info_t *info);
int check_attack_input(char *);
void send_attack(int *binary, char);
int *receive_attack(int *binary);
int attack(info_t *info, char *coord);
void wait_attack(info_t *);
int do_attack(int argc, info_t *info);
void modify_maps(int ac, info_t *info);
void check_attack(info_t *info);

#endif
