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
int usage(int, char **);
int error_handling(int);
char **create_map(void);
int navy(int, char **);
int file_error(int, char **, info_t *);
int check_file(char ***);
int player_connection(int, char **, info_t *);
void load_maps(info_t *);
int game_loop(int, info_t *);
void print_p1_turn(info_t *);
void print_p2_turn(info_t *);
char ***put_file_in_triple_array(char ***, int);
void init_struct(info_t *);
void load_boat(int, info_t *);
void free_all(info_t *);
int check_attack_input(char *, info_t *, int);
void send_attack(int *, char);
int *receive_attack(int *);
int attack(info_t *, char *);
void wait_attack(int, info_t *);
int do_attack(int, info_t *);
void modify_maps(int, info_t *);
void check_attack(void);
void send_binary(int, info_t *, int *, int *);
void send_attack_to_p1(int *, char, info_t *);
void send_attack_to_p2(int *, char, info_t *);
void modify_enemy_maps(info_t *, char **);
void check_win(int, info_t *);
int check_p1_win(info_t *);
int check_p2_win(info_t *);
int already_hit(int, info_t *);
int double_check(char *);
int check_boats(int, info_t *);

#endif
