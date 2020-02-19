/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_getbinary.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int *my_getbinary(int nbr, int *binary)
{
    int i = 0;
    int size = get_binary_size(nbr);

    binary = malloc(sizeof(int) * size);
    for (; nbr > 0; i++) {
        binary[i] = nbr % 2;
        nbr = nbr / 2;
    }
    binary[i] = 2;
    return (binary);
}
