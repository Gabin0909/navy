/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_attack_input.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

global_t global;

void send_attack_to_p2(int *binary, char atk, info_t *info)
{
    int len = get_binary_size(atk);

    for (; len > -1; len--) {
        if (binary[len] == 0) {
            kill(info->enemy_pid, SIGUSR1);
            usleep(4000);
        }
        else if (binary[len] == 1) {
            kill(info->enemy_pid, SIGUSR2);
            usleep(4000);
        }
    }
}

void send_attack_to_p1(int *binary, char atk, info_t *info)
{
    int len = get_binary_size(atk);

    my_printf("p1_pid: %d", info->p1_pid);
    for (; len > -1; len--) {
        if (binary[len] == 0) {
            kill(info->p1_pid, SIGUSR1);
            usleep(4000);
        }
        else if (binary[len] == 1) {
            kill(info->p1_pid, SIGUSR2);
            usleep(4000);
        }
    }
}

void wait_attack(info_t *info)
{
    int *binary = NULL;
    unsigned int letter = 0;
    unsigned int number = 0;

    info->input = malloc(sizeof(char) * 3);
    binary = malloc(sizeof(int) * 13);
    my_putstr("waiting for enemy's attack...\n");
    for (int i = 0; i != 13; i++) {
        binary = receive_attack(binary);
    }
    letter = my_tabint_to_int(binary, -1, 6);
    number = my_tabint_to_int(binary, 6, 12);
    info->input[0] = letter;
    info->input[1] = number;
    info->input[2] = '\0';
}

int do_attack(int argc, info_t *info)
{
    char *atk_pos = NULL;
    int *binary1 = NULL;
    int *binary2 = NULL;

    my_putstr("attack: ");
    atk_pos = get_next_line(0);
    if (atk_pos == NULL)
        return (84);
    if (check_attack_input(atk_pos) != 0) {
        my_putstr("wrong position\n");
        do_attack(argc, info);
    }
    binary1 = my_getbinary(atk_pos[0], binary1);
    binary2 = my_getbinary(atk_pos[1], binary2);
    if (argc == 2) {
        send_attack_to_p2(binary1, atk_pos[0], info);
        send_attack_to_p2(binary2, atk_pos[1], info);
    }
    if (argc == 3) {
        send_attack_to_p1(binary1, atk_pos[0], info);
        send_attack_to_p1(binary2, atk_pos[1], info);
    }
    return (0);
}

int check_attack_input(char *atk_pos)
{
    if ((atk_pos[0] < 'A' || atk_pos[0] > 'H')
    || (atk_pos[1] < '1' || atk_pos[1] > '8'))
        return (84);
    else if (my_strlen(atk_pos) != 2)
        return (84);
    return (0);
}
