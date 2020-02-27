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

int check_inside_file(int fd, info_t *info)
{
    info->boat_pos = put_file_in_triple_array(info->boat_pos, fd);
    if (info->boat_pos == NULL) {
        my_putstr("Too many boats.\n");
        return (1);
    }
    if (check_file(info->boat_pos) != 0)
        return (1);
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
