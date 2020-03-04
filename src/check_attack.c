/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_attack.c
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

void rec0(int sig)
{
    (void) sig;
    my_printf("hit\n\n");
    global.var = HIT;
}

void rec1(int sig)
{
    (void) sig;
    my_printf("missed\n\n");
    global.var = MISS;
}

void check_attack(void)
{
    struct sigaction sig0;
    struct sigaction sig1;

    sigemptyset(&sig0.sa_mask);
    sigemptyset(&sig1.sa_mask);
    sig0.sa_handler = &rec0;
    sig1.sa_handler = &rec1;
    sig0.sa_flags = 0;
    sig1.sa_flags = 0;
    sigaction(SIGUSR1, &sig0, NULL);
    sigaction(SIGUSR2, &sig1, NULL);
    pause();
}
