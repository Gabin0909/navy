/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** error_handling.c
*/

#include "lib.h"

int error_handling(int argc)
{
    if (argc != 3 && argc != 2) {
        my_putstr("Invalid arguments: ./navy -h for more help.\n");
        return (1);
    }
    return (0);
}
