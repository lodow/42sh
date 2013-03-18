##
## Makefile for minishell in /home/dellam_a//Projet/System Unix/minishell
##
## Made by adrien dellamaggiora
## Login   <dellam_a@epitech.net>
##
## Started on  Mon Dec 10 09:55:28 2012 adrien dellamaggiora
## Last update Thu Mar  7 17:01:47 2013 Adrien
##

SRC=	main.c \
	print.c \
	get_next_line.c \
	my_str_to_wordtab.c \
	my_strfunc.c \
	cd.c \
	env.c \
	pipe.c \
	handle_cmd.c \
	pid.c \
	redirec.c \
	redirg.c \
	misc.c

OBJ=	$(SRC:.c=.o)

NAME=	mysh

$(NAME):	$(OBJ)
	cc $(OBJ) -I. -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all