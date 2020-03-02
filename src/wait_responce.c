/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** wait_responce.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "lib.h"
#include "my.h"
#include "struct.h"

void send_responce(int argc, info_t *info)
{
    if (argc == 2)
        kill(SIGUSR1, info->enemy_pid);
    else
        kill(SIGUSR1, info->p1_pid);
}

void wait_responce(int argc, info_t *info)
{
    
    if (argc == 2) {
        pause();
    }
}
