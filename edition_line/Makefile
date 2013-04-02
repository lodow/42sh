## Makefile for Makefile in /home/robert_r//BSQ
## 
## Made by remi robert
## Login   <robert_r@epitech.net>
## 
## Started on  Fri Nov 30 10:59:19 2012 remi robert
## Last update Mon Apr  1 17:05:09 2013 remi robert
##

CC	=	gcc

TPATH	=	termcap/

LIBPATH	=	lib/

SRCPATH	=	./

SRC	=	$(SRCPATH)main.c				\
		$(SRCPATH)add_caractere.c			\
		$(SRCPATH)return_string.c			\
		$(SRCPATH)read_cmd.c				\
		$(SRCPATH)free.c				\
		$(SRCPATH)view_string.c				\
		$(SRCPATH)get_len_string_with_pos.c		\
		$(SRCPATH)gere_keyboard.c			\

TSRC	=	$(TPATH)ecrase_text.c				\
		$(TPATH)coordone.c				\
		$(TPATH)mod_raw.c				\
		$(TPATH)curseur.c				\
		$(TPATH)get_pos_curser.c			\
		$(TPATH)clear.c					\

LIBSRC	=	$(LIBPATH)my_putstr.c				\
		$(LIBPATH)my_strlen.c				\
		$(LIBPATH)my_getnbr.c				\

OBJ	=	$(SRC:.c=.o)

OBJLIB	=	$(LIBSRC:.c=.o)

OBJT	=	$(TSRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-g -Wall -Wextra -Iinclude -pedantic -ansi -ltermcap

$(NAME):	$(OBJ) $(OBJLIB) $(OBJT)
		$(CC) -o $(NAME) $(OBJ) $(OBJLIB) $(OBJT) $(CFLAGS)

all:		$(NAME)

clean:
		rm -f *~
		rm -f $(OBJ) $(OBJLIB) $(OBJT)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all termcap lib clean fclean re
