##
## Makefile for the Game_Of_Life Project
##

SRC	=	src/main.c
OBJ	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -g
CPPFLAGS	=	-I./include/
LIB_ADD	=	-lncurses
LIB_PATH	=	lib/my
NAME	=	GoL

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB_ADD) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
