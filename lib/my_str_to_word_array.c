/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** malloc_file
*/

#include <stdlib.h>
#include <stdio.h>

int skip_separators(char *buffer, char c, int i)
{
    for (; (buffer[i] == c && buffer[i + 1] == c)
    || (buffer[i] == ' ' && buffer[i + 1] == ' ')
    || (buffer[i] == c && buffer[i + 1] == ' ')
    || (buffer[i] == ' ' && buffer[i + 1] == c); i++);
    return (i);
}

int count_columns(char *buffer, char c)
{
    int colmn = 0;
    int count = 0;
    int i = 0;

    for (; buffer[i] == c || buffer[i] == ' '; i++);
    for (; buffer[i] != '\0'; i++, count++) {
        if (buffer[i] == c || buffer[i] == ' ') {
            if (colmn < count)
                colmn = count;
            i = skip_separators(buffer, c, i);
            count = 0;
        }
    }
    if (colmn < count)
        colmn = count;
    return (colmn);
}

int count_rows(char *buffer, char c)
{
    int rows = 0;
    int i = 0;

    for (; buffer[i] == c || buffer[i] == ' '; i++);
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == c || buffer[i] == ' ') {
            rows++;
            i = skip_separators(buffer, c, i);
        }
    }
    if (buffer[i - 1] != c && buffer[i - 1] != ' ')
        rows++;
    return (rows);
}

char **fill_map(char **map, char *buffer, char c)
{
    int a = 0;
    int b = 0;
    int i = 0;

    for (; buffer[i] == c || buffer[i] == ' '; i++);
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == c || buffer[i] == ' ') {
            map[a][b] = '\0';
            a++;
            b = 0;
            i = skip_separators(buffer, c, i);
        } else {
            map[a][b] = buffer[i];
            b++;
        }
    }
    if (buffer[i - 1] != c && buffer[i - 1] != ' ')
        map[a][b] = '\0';
    return (map);
}

char **my_str_to_word_array(char *str, char **map, char separator)
{
    int rows = 0;
    int colmn = 0;

    if (str == NULL)
        return (NULL);
    colmn = count_columns(str, separator);
    rows = count_rows(str, separator);
    map = malloc(sizeof(char *) * (rows + 1));
    for (int i = 0; i < rows; i++)
        map[i] = malloc(sizeof(char) * (colmn + 1));
    map[rows] = NULL;
    map = fill_map(map, str, separator);
    return (map);
}