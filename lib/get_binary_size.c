/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** get_binary_size.c
*/

int get_binary_size(int nbr)
{
    int size = 0;

    while (nbr > 0) {
        nbr = nbr / 2;
        size++;
    }
    return (size);
}
