## Makefile for Makefile in /home/robert_r//BSQ
## 
## Made by remi robert
## Login   <robert_r@epitech.net>
## 
## Started on  Fri Nov 30 10:59:19 2012 remi robert
## Last update Sat Mar  9 12:54:17 2013 remi
##

SRC=	src/main.c			\
	src/list_cmd.c			\
	src/run_loop.c			\
	src/read_cmd.c			\
	src/my_str_to_wordtab.c		\
	src/free.c			\
	src/prompt.c 			\
	src/my_putstr.c 		\
	src/list.c 			\
	src/char_env.c 			\
	src/exit.c 			\
	src/str_cmp.c 			\
	src/str_assemble.c 		\
	src/find_cmd.c 			\
	src/detect_type_op.c 		\
	src/parser_instruction.c 	\
	src/redirection.c 		\
	src/pipe.c 			\
	src/find_exec_other_path.c 	\
	src/fct_unsetenv.c 		\
	src/fct_setenv.c 		\
	src/fct_env.c 			\
	src/detect_fct.c 		\
	src/my_getnbr.c 		\
	src/fct_cd.c 		 	\
	src/gere_signal.c 		\
	src/loop_parser_instruction.c	\
	src/exec_pipe.c			\
	src/my_str_isprintable.c	\
	src/epure_str.c			\
	src/fct_cd_option.c		\
	src/get_next_line.c		\
	src/init_shell.c		\
	src/alias.c			\
	src/ascii_art.c			\
	src/return_path_conf.c		\
	src/fct_history.c		\
	src/rm_first_lm_list.c		\
	src/interpretation_env.c	\
	src/copy_inter_buff.c		\
	src/reformat_buff_cmd.c		\
	src/fct_echo.c			\
	src/print_echo.c		\
	src/func_alias.c		\
	src/func_cd.c			\
	src/acces_path.c		\
	src/test_type_cmd.c		\
	src/print_color.c		\
	src/file_cmd.c			\
	src/interpretation_string.c	\

OBJ=	 $(SRC:.c=.o)

CC=	gcc

NAME=	mysh

CFLAGS += -g -Wall -Wimplicit-function-declaration
CFLAGS += -pedantic -Wfatal-errors -Wuninitialized
CFLAGS += -Iinclude

$(NAME):$(OBJ)
	@echo "\n"
	$(CC)  -o $(NAME) $(OBJ)
	@echo "\n\t ===Compilation terminée===\n"

all:	$(NAME)

clean:
	rm -f *~
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
