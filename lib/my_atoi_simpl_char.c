/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_itoa_simpl_char
*/

int my_atoi_simpl(char ch)
{
    int a = 0;

    if (ch >= 48 && ch <= 57) {
            a *= 10;
            a += (ch - 48);
    }
    return (a);
}
