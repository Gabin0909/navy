/*
** EPITECH PROJECT, 2019
** delivery_re
** File description:
** my_strncmp
*/

int my_strcmp(char *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
    return (0);
}