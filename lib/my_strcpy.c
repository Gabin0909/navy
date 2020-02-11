/*
** EPITECH PROJECT, 2019
** delivery_re
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int z = 0;

    for (; src[z] != '\0'; z++)
        dest[z] = src[z];
    dest[z] = '\0';
    return (dest);
}