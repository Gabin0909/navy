/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_printf(char *str, ...);
int	my_put_nbr_base(int nb, char *base);
int my_strncmp(char *s1, char const *s2, int n);
char **my_strdup_double_char(char **dest, char **src);
char **my_strcpy_double_char(char **dest, char **src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char *s1, char const *s2);
void free_double_char(char **map);
int my_str_isnum(char const *str);
int my_str_isnumalpha(char const *str);
int my_atoi(char *str);
char *my_strcat(char *dest, char *str1, char *str2);
char *my_strdup(char *dest, char const *src);
char **my_str_to_word_array(char *str, char **map, char separator);
void print_double_char(char **d_str);

#endif /* !LIB_H_ */
