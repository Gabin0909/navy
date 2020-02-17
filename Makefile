##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	src/main.c\
			src/navy.c\
			src/create_map.c\
			src/check_connection.c\

NAME	=	navy

OBJ	=	$(SRC:.c=.o)

CFLAGS += -W -Wall -Wextra -pedantic -I./include

DEBUG += -W -Wall -Wextra -pedantic -g3 -I./include $(CSFML)

TEST	=	lib/test.c

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib
		gcc -o $(NAME) $(SRC) -L./lib -lmy $(CFLAGS) $(CSFML)

clean:
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
		gcc -o $(NAME) $(SRC) -L./lib/ -I./include -lmy $(DEBUG)

test_run:
		make -C ./tests/ test_run
