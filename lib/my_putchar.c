/*
** EPITECH PROJECT, 2018
** main_putchar.c
** File description:
** commande main putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
