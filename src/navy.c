/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "struct.h"
#include "lib.h"
#include "my.h"

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
    if (argc != 3 && argc != 2) {
        my_putstr("Invalid arguments: ./navy -h for more help.\n");
        return (84);
    }
    return (0);
}

int navy(int argc, char **argv)
{
    info_t info;

    if (argc == 2 && (argv[1][0] == '-' && argv[1][1] == 'h')) {
        usage();
        return (1);
    }
    if (error_handling(argc) == 84)
        return (84);
    info.empty_map = create_map();
    if (file_error(argc, argv) != 0)
        return (84);
    if (player_connection(argc, argv) != 0)
        return (84);
    return (0);
}
