##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Mon Oct 22 10:39:42 2012 hugues morisset
##

SRC= 	src/main.c \
		src/stc.c \
		src/str.c \
		src/shell.c \
		src/my_str_to_wordtab.c \
		src/signal.c \
		src/job.c \
		src/swap_ptr.c \
		src/env/env.c \
		src/builtins/builtins.c \
		src/builtins/fg.c \
		src/builtins/bg.c \
		src/builtins/jobs.c \
		src/builtins/robert.c \
		src/builtins/cd.c \
		src/builtins/echo.c \
		src/builtins/env.c \
		src/builtins/setenv.c \
		src/builtins/unsetenv.c \
		src/builtins/exit.c \
		src/get_next_line.c \
		src/ptr_tab.c

OBJ= $(SRC:.c=.o)

NAME= robertSH
CFLAGS= -g -Wall -Wfloat-equal -Wmissing-include-dirs \
	-Wclobbered -Wempty-body -Wignored-qualifiers \
	-Wmissing-field-initializers -Wmissing-parameter-type \
	-Wold-style-declaration -Woverride-init -Wsign-compare \
	-Wtype-limits -Wuninitialized

INVOCATION= gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(INVOCATION) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ) $(LIBOBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
