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

void receive_0(int sig)
{
    (void) sig;
    my_putchar('0');
    return;
}

void receive_1(int sig)
{
    (void) sig;
    my_putchar('1');
    return;
}

void send_attack(int *binary, char atk)
{
    int len = get_binary_size(atk);

    for (; len > -1; len--) {
        if (binary[len] == 0) {
            kill(global.enemy_pid, SIGUSR1);
            usleep(4000);
        }
        else if (binary[len] == 1) {
            kill(global.enemy_pid, SIGUSR2);
            usleep(4000);
        }
    }
}

char *receive_attack(void)
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
    return (NULL);
}
