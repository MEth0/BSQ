##
## Makefile for BSQ in /home/simon_z/rendu/CPE_2015_BSQ
## 
## Made by Morgan Simon
## Login   <simon_z@epitech.net>
## 
## Started on  Mon Nov 30 10:54:42 2015 Morgan Simon
## Last update Fri May 20 16:49:21 2016 Morgan SIMON
##

NAME	=	bsq

CC	=	gcc

SRC	=	src/main.c	\
		src/tools.c	\
		src/my_getnbr.c	\
		src/map.c	\
		src/find_square.c

INC	=	./include

CFLAGS	+=	-I$(INC) -Wall -Wextra -W

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
