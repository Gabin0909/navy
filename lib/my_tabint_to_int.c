/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_tabint_to_int.c
*/

#include <unistd.h>
#include <lib.h>

int my_pow(int x, int n)
{
    if (n == 0)
        return (1);
    else
        return (x*my_pow(x, n - 1));
}

unsigned int my_tabint_to_int(int *nbr, int finish, int index)
{
    int a = 0;
    int n = 0;

    for (int z = index; z > finish; z--) {
        a += (nbr[z] * (my_pow(2, n)));
        n += 1;
    }
    return (a);
}
