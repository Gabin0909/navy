##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 Day10
##

SRC	=	    my_putchar.c				\
			my_putstr.c 				\
			my_put_nbr.c				\
			my_put_nbr_base.c 			\
			my_printf.c 				\
			my_strlen.c 				\
			my_strncmp.c 				\
			my_strcmp.c 				\
			my_strdup_double_char.c 	\
			my_strdup.c 				\
			my_strcpy_double_char.c 	\
			my_strcpy.c 				\
			my_str_to_word_array.c 		\
			my_atoi.c 					\
			my_str_isnum.c 				\
			my_str_isnumalpha.c 		\
			my_strcat.c 				\
			my_itoa.c 					\
			my_atoi_simpl_char.c 		\
			print_double_char.c 		\
			free_double_char.c 			\
			free_triple_array.c 		\
			get_next_line.c 			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	@echo -e "\033[1;35m[Compiling library...]\033[0;13m"
	gcc -c $(SRC) -I../include/ -g3
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

re:
	rm libmy.a