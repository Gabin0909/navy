/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Task03
*/

int my_strlen(char const *str)
{
    int z = 0;

    for (; str[z] != '\0'; z++);
    return (z);
}