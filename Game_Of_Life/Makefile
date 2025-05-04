##
## Makefile for the Game_Of_Life Project
##

SRC	=	src/main.c	\
		src/help.c	\
		src/game.c	\
		src/parsing.c
OBJ	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -g
CPPFLAGS	=	-I./include/
LIB_ADD	=	-lncurses
LIB_PATH	=	lib/my
NAME	=	GoL
ifeq ($(ENV), dev)
	CFLAGS	+=	-g3
endif

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB_ADD)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
