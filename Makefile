##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	src/main.c						\
			src/navy.c						\
			src/usage.c						\
			src/error_handling.c			\
			src/create_map.c				\
			src/file_error.c				\
			src/check_file.c				\
			src/player_connection.c			\
			src/game_loop.c					\
			src/print_players_turn.c		\
			src/put_file_in_triple_array.c	\
			src/init_struct.c 				\
			src/load_boat.c 				\
			src/free_all.c 					\
			src/manage_attack_input.c 		\
			src/manage_attack.c				\
			src/modify_map.c 				\
			src/check_attack.c				\

NAME	=	navy

OBJ	=	$(SRC:.c=.o)

CFLAGS += -W -Wall -Wextra -pedantic -I./include -L./lib -lmy

DEBUG += $(CFLAGS) -g3

TEST	=	lib/test.c

all:	$(NAME)

$(NAME): 	$(OBJ)
	make -C lib
	@echo -e "\033[1;35m[Compiling sources with library...]\033[0;13m"
	gcc -o $(NAME) $(SRC) $(CFLAGS)
	@echo -e "\033[1;32m[Compilation Completed !]\033[0;13m"

clean:
	@echo -e "\033[1;31m[Deleting files...]\033[0;13m"
	rm -f lib/*.o
	rm -f $(OBJ)
	rm -f a.out
	rm -f vgcore.*

fclean: clean
	rm -f $(NAME)
	rm -f lib/libmy.a

test_fclean: clean
	make -C ./tests/ fclean

re: fclean all

debug:	fclean
	make -C lib/
	@echo -e "\033[1;35m[Compiling for debug...]\033[0;13m"
	gcc -o $(NAME) $(SRC) $(DEBUG)
	@echo -e "\033[1;32m[Compilation Completed !]\033[0;13m"

test_run:
	make -C ./tests/ test_run
