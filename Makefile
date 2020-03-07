##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC 		= 	gcc

SRC		=	src/navy.c						\
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
			src/check_win.c					\
			src/already_hit.c				\

SRC_MAIN	= src/main.c

OBJ_TEST 	= $(SRC:.c=.o)

OBJ 		= $(SRC:.c=.o) $(SRC_MAIN:.c=.o)

NAME	=	navy

NAME_TEST = unit_tests

CFLAGS += -W -Wall -Wextra -pedantic -I./include -L./lib -lmy

DEBUG += $(CFLAGS) -g3

all:	$(NAME)

$(NAME): 	$(OBJ)
	make -C lib
	@echo -e "\033[1;35m[Compiling sources with library...]\033[0;13m"
	$(CC) -o $(NAME) $(SRC) $(SRC_MAIN) $(CFLAGS)
	@echo -e "\033[1;32m[Compilation Completed !]\033[0;13m"

clean:
	@echo -e "\033[1;31m[Deleting files...]\033[0;13m"
	rm -f *.o
	rm -f lib/*.o
	rm -f $(OBJ)
	rm -f a.out
	rm -f *.gcno
	rm -f *.gcda
	rm -f vgcore.*

fclean: clean
	rm -f $(NAME)
	rm -f lib/libmy.a
	rm -f $(NAME_TEST)

re: fclean all

debug:	fclean
	make -C lib/
	@echo -e "\033[1;35m[Compiling for debug...]\033[0;13m"
	$(CC) -o $(NAME) $(SRC) $(DEBUG)
	@echo -e "\033[1;32m[Compilation Completed !]\033[0;13m"

tests_run:
	@echo -e "\033[1;35m[Compiling for unit tests...]\033[0;13m"
	$(CC) $(SRC) ./lib/*.c -c --coverage $(CFLAGS)
	$(CC) tests/tests_navy.c -c $(CFLAGS)
	$(CC) -o $(NAME_TEST) *.o -lcriterion -lgcov
	./$(NAME_TEST)
	gcovr --exclude tests/
	@echo -e "\033[1;32m[Unit tests done !]\033[0;13m"

.PHONY: all clean fclean re debug tests_run