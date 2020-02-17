/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** get_next_line
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int m_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_strncpy(char *dest, char const *src, int i)
{
    int j = 0;

    for (; src[j] != '\0' && j < i; j++)
        dest[j] = src[j];
    if (j == i)
        dest[j] = '\0';
    return (dest);
}

char *add(int *buff_count, int i, char *line, char *buffer)
{
    int init_length = 0;
    char *returned = NULL;

    if (line != 0)
        init_length = m_strlen(line);
    else
        init_length = 0;
    returned = malloc(sizeof(*returned) * (init_length + i + 1));
    if (returned == NULL)
        return (NULL);
    if (line)
        my_strncpy(returned, line, init_length);
    else
        my_strncpy(returned, "", init_length);
    my_strncpy(returned + init_length, buffer + *buff_count, i);
    *buff_count += i + 1;
    free(line);
    return (returned);
}

char *get_next_line(int fd)
{
    char *line = NULL;
    int i = 0;
    static char buffer[READ_SIZE];
    static int read_return;
    static int buff_count;

    while (1) {
        if (read_return <= buff_count) {
            if (!(read_return = read(fd, buffer, READ_SIZE)))
                return (line);
            else if (read_return == -1)
                return (NULL);
            i = 0;
            buff_count = 0;
        }
        if (buffer[buff_count + i] == '\n')
            return (add(&buff_count, i, line, buffer));
        else if (buff_count + i == read_return - 1)
            line = add(&buff_count, i + 1, line, buffer);
        i++;
    }
}
