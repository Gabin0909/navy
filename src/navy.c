/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "lib.h"

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("      ./navy [first_player_pid] navy_positions\n");
    my_putstr("Description\n");
    my_putstr("     first_player_pid:  only for the 2nd player. pid pf\
    the first player\n");
    my_putstr("navy_positions:  fiel representing the positions of the\
    ships.\n");
}

int error_handling(int argc)
{
    if (argc != 3) {
        my_putstr("Invalid arguments: ./navy -h for more help.\n");
        return (84);
    }
    return (0);
}

int navy(int argc, char **argv)
{
    if (argc == 2 && (argv[1][0] == '-' && argv[1][1] == 'h')) {
        usage();
        return (1);
    }
    if (error_handling(argc) == 84)
        return (84);
    return (0);
}
