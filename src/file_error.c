/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** file_error
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include "lib.h"
#include "my.h"

int corresponding_boats(char **boat, int i)
{
    char x = boat[1][0];
    char y = boat[1][1];
    char a = boat[2][0];
    char b = boat[2][1];
    int count = 0;

    if (x != a) {
        for (; x < a; count++, x++);
        if (count != (i + 1))
            return (1);
    } else if (y != b) {
        for (; y < b; count++, y++);
        if (count != (i + 1))
            return (1);
    }
    return (0);
}

int check_inside_file(int fd, info_t *info)
{
    info->boat_pos = put_file_in_triple_array(info->boat_pos, fd);
    if (info->boat_pos == NULL) {
        my_putstr("Wrong arguments.\n");
        return (1);
    }
    if (check_file(info->boat_pos) != 0)
        return (1);
    for (int i = 0; info->boat_pos[i] != NULL; i++) {
        if (corresponding_boats(info->boat_pos[i], i) != 0) {
            my_putstr("Boat length doesn't match its position.\n");
            return (1);
        }
    }
    return (0);
}

int file_error(int ac, char **av, info_t *info)
{
    int fd = 0;

    if (ac == 2) {
        if ((fd = open(av[1], O_RDONLY)) == -1) {
            my_putstr("File does not exist.\n");
            return (1);
        }
        else
            return (check_inside_file(fd, info));
    } else if (ac == 3) {
        if ((fd = open(av[2], O_RDONLY)) == -1)
            return (1);
        else
            return (check_inside_file(fd, info));
    }
    return (0);
}
