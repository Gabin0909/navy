/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** manage_attack.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

global_t global;

void send_binary(int argc, info_t *info, int *binary1, int *binary2)
{
    binary1 = my_getbinary(info->atk_pos[0], binary1);
    binary2 = my_getbinary(info->atk_pos[1], binary2);
    if (argc == 2) {
        send_attack_to_p2(binary1, info->atk_pos[0], info);
        send_attack_to_p2(binary2, info->atk_pos[1], info);
    }
    if (argc == 3) {
        send_attack_to_p1(binary1, info->atk_pos[0], info);
        send_attack_to_p1(binary2, info->atk_pos[1], info);
    }
}

int *fill_binary(int *binary)
{
    static int i = 0;

    if (i == 13)
        i = 0;
    binary[i] = global.var;
    i++;
    return (binary);
}

void receive_0(int sig)
{
    (void) sig;
    global.var = 0;
    return;
}

void receive_1(int sig)
{
    (void) sig;
    global.var = 1;
    return;
}

int *receive_attack(int *binary)
{
    struct sigaction signal0;
    struct sigaction signal1;

    sigemptyset(&signal0.sa_mask);
    sigemptyset(&signal1.sa_mask);
    signal0.sa_handler = &receive_0;
    signal1.sa_handler = &receive_1;
    signal0.sa_flags = 0;
    signal1.sa_flags = 0;
    sigaction(SIGUSR1, &signal0, NULL);
    sigaction(SIGUSR2, &signal1, NULL);
    pause();
    binary = fill_binary(binary);
    return (binary);
}
