/*
** EPITECH PROJECT, 2019
** delivery_re
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int a = 0;

    for (int z = 0; str[z] != '\0'; z++) {
        if (str[z] >= 48 && str[z] <= 57) {
            a *= 10;
            a += (str[z] - 48);
        }
        else
            return (a);
    }
    return (a);
}