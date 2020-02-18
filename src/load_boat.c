/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** load_boat.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include "lib.h"
#include "struct.h"
#include "my.h"

void first_player_boats(char ***boat_pos)
{
    
}

void load_boat(int argc, char **argv, info_t info)
{
    char ***boat_pos = NULL;
    int fd = 0;

    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        boat_pos = put_file_in_triple_array(boat_pos, fd);
        first_player_boats(boat_pos);
        close(fd);
        free_triple_array(boat_pos);
    }
    else if (argc == 3) {
        fd = open(argv[2], O_RDONLY);
        boat_pos = put_file_in_triple_array(boat_pos, fd);
        second_player_boats(boat_pos);
        close(fd);
        free_triple_array(boat_pos);
    }
}
