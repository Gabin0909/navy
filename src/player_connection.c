/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** player_connection.c
*/

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "struct.h"
#include "lib.h"
#include "my.h"

int connect_player_one(void)
{
    pid_t pid = getpid();

    my_printf("my_pid:  %d\n", pid);
    my_putstr("Waiting for enemy connection...\n\n");
    pause();
    my_putstr("enemy conncted\n");
    return (0);
}

int connect_player_two(char **argv)
{
    pid_t pid_1 = 0;
    pid_t pid_2 = getpid();

    pid_1 = my_atoi(argv[1]);
    my_printf("my_pid:  %d\n", pid_2);
    kill(pid_1, SIGUSR1);
    my_putstr("successfully connected\n");
    return (0);
}

int player_connection(int argc, char **argv)
{
    if (argc == 2)
        connect_player_one();
    if (argc == 3)
        connect_player_two(argv);
    return (0);
}
