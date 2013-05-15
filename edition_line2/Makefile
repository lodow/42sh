##
## Makefile for Makefile in /home/robert_r//BSQ
## 
## Made by remi robert
## Login   <robert_r@epitech.net>
## 
## Started on  Fri Nov 30 10:59:19 2012 remi robert
## Last update Tue May 14 17:56:41 2013 remi robert
##

CC	=	gcc

TPATH	=	termcap/

LIBPATH	=	lib/

SRCPATH	=	src/

SRC	=	$(SRCPATH)main.c				\
		$(SRCPATH)read_cmd.c				\
		$(SRCPATH)gere_keyboard.c			\
		$(SRCPATH)decal_string.c			\
		$(SRCPATH)view.c				\
		$(SRCPATH)suppression.c				\
		$(SRCPATH)gere_control.c			\
		$(SRCPATH)start_end_cmd.c			\
		$(SRCPATH)clear.c				\
		$(SRCPATH)signal.c				\
		$(SRCPATH)control_y.c				\
		$(SRCPATH)control_k.c				\
		$(SRCPATH)update_pos.c				\
		$(SRCPATH)refresh_view.c			\
		$(SRCPATH)gere_window.c				\
		$(SRCPATH)globb.c				\
		$(SRCPATH)return_globb_str.c			\
		$(SRCPATH)view_globb.c				\
		$(SRCPATH)completation.c			\
		$(SRCPATH)plus_completation.c			\

TSRC	=	$(TPATH)coordone.c				\
		$(TPATH)mod_raw.c				\
		$(TPATH)curseur.c				\
		$(TPATH)get_pos_curser.c			\
		$(TPATH)clear.c					\
		$(TPATH)verif_env.c				\
		$(TPATH)save_curser.c				\
		$(TPATH)init_termcap.c				\
		$(TPATH)apply_termcap.c				\
		$(TPATH)print_termcap.c				\

LIBSRC	=	$(LIBPATH)my_putstr.c				\
		$(LIBPATH)my_strlen.c				\
		$(LIBPATH)my_getnbr.c				\
		$(LIBPATH)my_memset.c				\
		$(LIBPATH)str_cmp.c				\

OBJ	=	$(SRC:.c=.o)

OBJLIB	=	$(LIBSRC:.c=.o)

OBJT	=	$(TSRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-g -Wall -Wfloat-equal -Wmissing-include-dirs \
		-Wclobbered -Wempty-body -Wignored-qualifiers \
		-Wmissing-field-initializers -Wmissing-parameter-type \
		-Wold-style-declaration -Woverride-init -Wsign-compare \
		-Wtype-limits -Wuninitialized -ltermcap -Iinclude

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
