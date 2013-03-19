##
## Makefile for copylib in /home/sinet_l//jour11
## 
## Made by luc sinet
## Login   <sinet_l@epitech.net>
## 
## Started on  Mon Oct 22 10:27:19 2012 luc sinet
## Last update Sun Mar 10 19:36:58 2013 luc sinet
##

SRCS	= main.c \
	  get_next_line.c \
	  my_str_to_wordtab.c \
	  adds.c \
	  nb.c \
	  str.c \
	  strfunc.c \
	  prompt.c \
	  cmd.c \
	  pars_cmd.c \
	  errors.c \
	  exec_cmd.c \
	  env.c \
	  cd.c \
	  other_builtins.c \
	  alias.c \
	  alias_load.c \
	  output.c \
	  input.c \
	  pipe.c \
	  pipe_exec.c \
	  double_out.c \
	  init.c


OBJS	= $(SRCS:.c=.o)

CC	= cc

RM	= rm -f

NAME	= mysh

$(NAME): 	$(OBJS)
	$(CC) $(SRCS) -o $(NAME) $(OPT)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean