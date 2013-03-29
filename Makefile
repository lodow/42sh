##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Mon Oct 22 10:39:42 2012 hugues morisset
##

SRC= 	src/main.c

OBJ= $(SRC:.c=.o)

NAME= mysh

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
