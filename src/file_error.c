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

char ***put_file_in_triple_array(char ***boat_pos, int fd)
{
    char *buff = NULL;
    int j = 0;

    boat_pos = malloc(sizeof(char **) * 5);
    for (; (buff = get_next_line(fd)) != NULL; j++) {
        boat_pos[j] = my_str_to_word_array(buff, boat_pos[j], ':');
        free(buff);
    }
    boat_pos[j] = NULL;
    return (boat_pos);
}

int check_inside_file(int fd)
{
    char ***boat_pos = NULL;

    boat_pos = put_file_in_triple_array(boat_pos, fd);
    close(fd);
    if (check_file(boat_pos) != 0) {
        free_triple_array(boat_pos);
        return (1);
    }
    free_triple_array(boat_pos);
    return (0);
}

int file_error(int ac, char **av)
{
    int fd = 0;

    if (ac == 2) {
        if ((fd = open(av[1], O_RDONLY)) == -1)
            return (1);
        else
            return (check_inside_file(fd));
    } else if (ac == 3) {
        if ((fd = open(av[2], O_RDONLY)) == -1)
            return (1);
        else
            return (check_inside_file(fd));
    }
    return (0);
}