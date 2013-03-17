##
## Makefile for my_ls in /home/lavand_m//my_ls
## 
## Made by maxime lavandier
## Login   <lavand_m@epitech.net>
## 
## Started on  Thu Nov 29 02:35:13 2012 maxime lavandier
## Last update Thu Mar  7 23:15:22 2013 maxime lavandier
##

SRCS	= main.c \
	  redir.c \
	  exec.c \
	  pipe.c \
	  list.c \
	  my_malloc.c \
	  my_put.c \
	  my_strcpy.c \
	  my_strlen.c \
	  recup.c \
	  str_to_wordtab.c \
	  strcmp.c \
	  search.c \
	  my_strcat.c \
	  double_strcat.c \
	  builtin.c \
	  pwd.c

NAME	= mysh

OBJS	= $(SRCS:.c=.o)

CFLAGS= 

$(NAME): $(OBJS)
	 cc $(OBJS) -o $(NAME)

all: 	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all