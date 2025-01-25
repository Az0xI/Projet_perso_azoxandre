##
## EPITECH PROJECT, 2024
## Arknights_Road_To_The_Legend
## File description:
## Makefile that compile my arknights fangame
##

SRC	=	source/main.c	\
		source/menu.c	\
		source/tutorial.c	\
		source/event.c
OBJ	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -g
CPPFLAGS	=	-I./include/
LIB_ADD	=	-lncurses
LIB_PATH	=	lib/my
NAME	=	arknights_RTTL

.SILENT: $(NAME)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB_ADD) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
