##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	src/main.c\
			src/navy.c\

NAME	=	navy

OBJ	=	$(SRC:.c=.o)

CSFML += -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window

CFLAGS += -W -Wall -Wextra -pedantic -I./include -Wno-deprecated

DEBUG += -W -Wall -Wextra -pedantic -g3 -I./include $(CSFML)

TEST	=	lib/test.c

all:	$(NAME)

$(NAME):	$(OBJ)
		@echo "\033[1;35mCompiling lib....\033[0;53m"
		make -C lib
		gcc -o $(NAME) $(SRC) -L./lib -lmy $(CFLAGS) $(CSFML)
		@echo "\033[1;34mCompilation Completed !\033[0;43m"

clean:
		rm -f lib/*.o
		rm -f $(OBJ)
		rm -f a.out
		rm -f vgcore.*

fclean: clean
		@echo "\033[1;31mDeleting files...\033[0;13m"
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
