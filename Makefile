##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	*.c

OBJ = $(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -Wall -g3 -Wextra -o $(NAME) $(OBJ) -lncurses

$(OBJ):
	gcc -Wall -Wextra -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
