##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Mon Apr 15 09:58:19 2013 remi robert
##

CC	=	gcc

RM	= 	rm

NAME	=	robertSH

COMPILEFLAG	=	-g -Wall -Wfloat-equal -Wmissing-include-dirs \
		-Wclobbered -Wempty-body -Wignored-qualifiers \
		-Wmissing-field-initializers -Wmissing-parameter-type \
		-Wold-style-declaration -Woverride-init -Wsign-compare \
		-Wtype-limits -Wuninitialized

INCLUDE	= 	-Iinclude/

LIBS	= 	-ltermcap

CFLAGS	= 	$(COMPILEFLAG) $(INCLUDE)

SRCPATH	=	src
BUILTINS=	src/builtins
PATHLINE=	src/edition_line
LIBLINE	=	src/edition_line/lib
PATHTERMCAP=	src/edition_line/termcap
PATHENV	=	src/env
PATHRED	=	src/redirection
PATHGLOBB=	src/edition_line/globb

SRC	= 	$(SRCPATH)/main.c				\
		$(SRCPATH)/stc.c				\
		$(SRCPATH)/backquotes.c				\
		$(SRCPATH)/inib_str_to_wordtab.c		\
		$(SRCPATH)/str.c				\
		$(SRCPATH)/my_uint64_t_strbase.c		\
		$(SRCPATH)/tr_str.c				\
		$(SRCPATH)/shell.c				\
		$(SRCPATH)/str_to_wordtab.c			\
		$(SRCPATH)/signal.c				\
		$(SRCPATH)/job.c				\
		$(SRCPATH)/jobs_forground.c			\
		$(SRCPATH)/is_grp_exec.c			\
		$(SRCPATH)/fd.c					\
		$(SRCPATH)/swap_ptr.c				\
		$(SRCPATH)/alias.c				\
		$(SRCPATH)/parse_cmd.c				\
		$(SRCPATH)/process_group.c			\
		$(SRCPATH)/exec_process.c			\
		$(SRCPATH)/tty.c				\
		$(SRCPATH)/pipe.c				\
		$(SRCPATH)/cmd.c				\
		$(SRCPATH)/wait.c				\
		$(SRCPATH)/load_conf.c				\
		$(SRCPATH)/cmd_full_path.c			\
		$(SRCPATH)/ptr_tab.c				\
		$(SRCPATH)/get_next_line.c			\
		$(SRCPATH)/get_file.c				\
		$(SRCPATH)/variable.c				\
		$(SRCPATH)/my_getnbr.c				\
		$(SRCPATH)/clean_tab.c				\
		$(SRCPATH)/error.c				\
		$(SRCPATH)/my_exit.c				\
		$(SRCPATH)/detect_redirection.c			\
		$(SRCPATH)/my_put_nbr.c				\
		$(SRCPATH)/my_putchar.c				\
		$(SRCPATH)/delete_history.c			\
		$(SRCPATH)/history.c				\

ENV	=	$(PATHENV)/env.c				\

SRCBUILTINS=	$(BUILTINS)/builtins.c				\
		$(BUILTINS)/fg.c				\
		$(BUILTINS)/bg.c				\
		$(BUILTINS)/jobs.c				\
		$(BUILTINS)/robert.c				\
		$(BUILTINS)/cd.c				\
		$(BUILTINS)/echo.c				\
		$(BUILTINS)/env.c				\
		$(BUILTINS)/setenv.c				\
		$(BUILTINS)/unsetenv.c				\
		$(BUILTINS)/exit.c				\
		$(BUILTINS)/history.c				\
		$(BUILTINS)/alias.c				\

SRCLINE	=	$(PATHLINE)/main_line.c				\
		$(PATHLINE)/add_caractere.c			\
		$(PATHLINE)/return_string.c			\
		$(PATHLINE)/read_cmd.c				\
		$(PATHLINE)/free.c				\
		$(PATHLINE)/view_string.c			\
		$(PATHLINE)/get_len_string_with_pos.c		\
		$(PATHLINE)/gere_keyboard.c			\
		$(PATHLINE)/suppression.c			\
		$(PATHLINE)/gere_control.c			\
		$(PATHLINE)/gere_buff_copy.c			\
		$(PATHLINE)/gere_buff_feature.c			\
		$(PATHLINE)/set_pos_curser.c			\
		$(PATHLINE)/init_struct_param.c			\
		$(PATHLINE)/print_prompt.c			\
		$(PATHLINE)/control_clear.c			\
		$(PATHLINE)/gere_direct_pos_cursor.c		\
		$(PATHLINE)/gere_valide_saisi.c			\
		$(PATHLINE)/add_history.c			\
		$(PATHLINE)/gere_history.c			\
		$(PATHLINE)/feature_history.c			\
		$(PATHLINE)/gere_current_history.c		\

SRCGLOBB=	$(PATHGLOBB)/globb.c				\
		$(PATHGLOBB)/genere_globb_str.c			\

SRCRED	=	$(PATHRED)/find_redirection.c			\
		$(PATHRED)/parse_redirection.c			\
		$(PATHRED)/redirection.c			\
		$(PATHRED)/reform_str_cmd.c			\
		$(PATHRED)/rempl_redirection.c			\
		$(PATHRED)/return_type_char.c			\

SRCLIBLINE=	$(LIBLINE)/str_cmp.c				\
		$(LIBLINE)/my_memset.c				\
		$(LIBLINE)/my_putstr.c				\

SRCTERMCAP=	$(PATHTERMCAP)/ecrase_text.c			\
		$(PATHTERMCAP)/coordone.c			\
		$(PATHTERMCAP)/mod_raw.c			\
		$(PATHTERMCAP)/curseur.c			\
		$(PATHTERMCAP)/get_pos_curser.c			\
		$(PATHTERMCAP)/clear.c				\
		$(PATHTERMCAP)/dl_current_pos.c			\

OBJ	=	$(SRC:.c=.o) 					\
		$(SRCBUILTINS:.c=.o) 				\
		$(ENV:.c=.o) 					\
		$(SRCLINE:.c=.o) 				\
		$(SRCLIBLINE:.c=.o) 				\
		$(SRCTERMCAP:.c=.o) 				\
		$(SRCRED:.c=.o) 				\
		$(SRCGLOBB:.c=.o) 				\

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIBS)

all:		$(NAME)

clean:
		$(RM) -f $(OBJ)

fclean:		clean
		$(RM) -f $(NAME)

re:		fclean all
