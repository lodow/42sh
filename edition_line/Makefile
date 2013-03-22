## Makefile for Makefile in /home/robert_r//BSQ
## 
## Made by remi robert
## Login   <robert_r@epitech.net>
## 
## Started on  Fri Nov 30 10:59:19 2012 remi robert
## Last update Fri Mar 22 13:07:09 2013 remi
##

SRC=	main.c \
	termcap/coordone.c \
	termcap/mod_raw.c \
	termcap/clear.c \
	my_putstr.c \
	termcap/curseur.c \
	add_caractere_string.c \
	return_string.c \
	read_cmd.c \
	free.c \
	get_pos_curser.c \
	my_strlen.c \
	my_getnbr.c \
	suppr_caractere_string.c \

OBJ=	 $(SRC:.c=.o)

OBJLIB=	 $(SRCLIB:.c=.o)

NAME=	mysh

CFLAGS= -g

$(NAME):$(OBJ) $(OBJLIB)
	@echo -e "\n\E[33;01m";
	cc  -o $(NAME) $(OBJ) $(OBJLIB) -ltermcap
	@echo -e "\E[33;00m\E[44;01mCompilation Términée\E[33;00m\n";

all:	$(NAME)

clean:
	rm -f *~
	rm -f $(OBJ) $(OBJLIB) $(OBJLIST)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
