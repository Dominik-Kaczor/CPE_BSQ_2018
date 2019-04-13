##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my_popup
##

CFLAGS	=	-Wall -Wextra

SRC	=	src/bsq.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		src/my_getnbr.c	\
		src/tools_bsq.c	\

SRC_TEST =	tests/main.c	\
		tests/test_bsq.c	\
		src/my_putchar.c        \
                src/my_putstr.c \
		src/my_getnbr.c \
		src/tools_bsq.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)

tests_run:	$(OBJ)
		gcc -o test $(SRC_TEST) --coverage -lcriterion
		./test

tests_clean :
		rm -f test
		rm -f *.gcda
		rm -f *.gcno

clean:
		rm  -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
