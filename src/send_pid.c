/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** send_pid.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "struct.h"
#include "lib.h"
#include "my.h"

void receive_0(int sig)
{
}

void receive_1(int sig)
{
}

void catch_p2_pid(info_t *info)
{
    struct sigaction signal0;
    struct sigaction signal1;
    int pid = getpid();
    int len = get_binary_size(pid +1);

    info->p2_binary = malloc(sizeof(int) * (len - 1));
    sigemptyset(&signal0.sa_mask);
    sigemptyset(&signal1.sa_mask);
    signal0.sa_handler = &receive_0;
    signal1.sa_handler = &receive_1;
    signal0.sa_flags = 0;
    signal1.sa_flags = 0;
    sigaction(SIGUSR1, &signal0, NULL);
    sigaction(SIGUSR2, &signal1, NULL);
}

void send_to_p1(int *binary, int pid)
{
    int len = get_binary_size(pid);

    for (; len > -1; len--) {
        if (binary[len] == 0)
            kill(pid, SIGUSR1);
        else if (binary[len] == 1)
            kill(pid, SIGUSR2);
        my_printf("len: %d\n", len);
    }
}

void send_pid(info_t *info)
{
    int *binary = NULL;

    binary = my_getbinary(info->p2_pid, binary);
    my_putstr("binary: ");
    for (int i = 0; binary[i] != 2; i++) {
        my_put_nbr(binary[i]);
    }
    my_putchar('\n');
    send_to_p1(binary, info->p1_pid);
}
