##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Mon Oct 22 10:39:42 2012 hugues morisset
##

SRC= 	main.c \
	parse_env.c \
	search_check_exec.c \
	getcheck_uin.c \
	get_next_line.c \
	signal_forward.c \
	my_str_to_wordtab.c \
	cat.c \
	get_file.c \
	redirection.c \
	closefd_check.c \
	pwd.c \
	alias.c \
	load_conf.c \
	clean_tab.c \
	pipe_it.c \
	swap_ptr.c \
	son_exec.c \
	under_cmd.c \
	wait.c \
	builtins_check.c \
	job_builtins.c \
	job.c \
	variable.c \
	epur_str.c \
	builtin.c \
	backquote.c \
	my_getnbr.c \
	my_uint64_t_strbase.c \
	stc.c

OBJ= $(SRC:.c=.o)

NAME= mysh

CFLAGS= -g -Wall -Wfloat-equal -Wmissing-include-dirs \
	-Wclobbered -Wempty-body -Wignored-qualifiers \
	-Wmissing-field-initializers -Wmissing-parameter-type \
	-Wold-style-declaration -Woverride-init -Wsign-compare \
	-Wtype-limits -Wuninitialized

INVOCATION= cc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(INVOCATION) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ) $(LIBOBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
