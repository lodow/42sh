##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login <moriss_h@epitech.net>
##
## Started on Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Fri May 24 17:56:53 2013 maxime lavandier
##

CC		=	gcc

RM		=	rm

NAME		=	42SH

COMPILEFLAG	=	-ggdb3 -Wall -Wfloat-equal -Wmissing-include-dirs \
			-Wclobbered -Wempty-body -Wignored-qualifiers \
			-Wmissing-field-initializers -Wmissing-parameter-type \
			-Wold-style-declaration -Woverride-init -Wsign-compare \
			-Wtype-limits -Wuninitialized

INCLUDE		=	-Iinclude/

LIBS		=	-ltermcap

CFLAGS		=	$(COMPILEFLAG) $(INCLUDE)

SRCPATH		=	src
BUILTINS	=	src/builtins
PATHLINE	=	src/edition_line/
LIBLINE		=	src/edition_line/lib
PATHTERMCAP	=	src/edition_line/termcap/
PATHENV		=	src/env
PATHRED		=	src/redirection
PATHGLOBB	=	src/edition_line/globb

SRC		=	$(SRCPATH)/main.c \
			$(SRCPATH)/stc.c \
			$(SRCPATH)/backquotes.c \
			$(SRCPATH)/inib_str_to_wordtab.c \
			$(SRCPATH)/str.c \
			$(SRCPATH)/my_uint64_t_strbase.c \
			$(SRCPATH)/tr_str.c \
			$(SRCPATH)/shell.c \
			$(SRCPATH)/str_to_wordtab.c \
			$(SRCPATH)/mult_str_to_wordtab.c \
			$(SRCPATH)/signal.c \
			$(SRCPATH)/job.c \
			$(SRCPATH)/jobs_forground.c \
			$(SRCPATH)/is_grp_exec.c \
			$(SRCPATH)/fd.c \
			$(SRCPATH)/swap_ptr.c \
			$(SRCPATH)/alias.c \
			$(SRCPATH)/parse_cmd.c \
			$(SRCPATH)/process_group.c \
			$(SRCPATH)/exec_process.c \
			$(SRCPATH)/tty.c \
			$(SRCPATH)/pipe.c \
			$(SRCPATH)/cmd.c \
			$(SRCPATH)/wait.c \
			$(SRCPATH)/load_conf.c \
			$(SRCPATH)/store_conf.c \
			$(SRCPATH)/cmd_full_path.c \
			$(SRCPATH)/ptr_tab.c \
			$(SRCPATH)/get_next_line.c \
			$(SRCPATH)/get_file.c \
			$(SRCPATH)/variable.c \
			$(SRCPATH)/my_getnbr.c \
			$(SRCPATH)/clean_tab.c \
			$(SRCPATH)/error.c \
			$(SRCPATH)/my_exit.c \
			$(SRCPATH)/my_put_nbr.c \
			$(SRCPATH)/my_putchar.c \
			$(SRCPATH)/delete_history.c \
			$(SRCPATH)/history.c \
			$(SRCPATH)/init_edition_line.c \
			$(SRCPATH)/add_history.c \
			$(SRCPATH)/gere_history.c \
			$(SRCPATH)/gere_valide_saisi.c \
			$(SRCPATH)/and_or.c \
			$(SRCPATH)/redirection.c \
			$(SRCPATH)/user_input.c \
			$(SRCPATH)/cat.c \
			$(SRCPATH)/reg_expr.c \
			$(SRCPATH)/rempl_str_inib.c \
			$(SRCPATH)/str_fille_tstr.c \
			$(SRCPATH)/check_if_folder.c \
			$(SRCPATH)/parseur_history.c

ENV		=	$(PATHENV)/env.c

SRCBUILTINS	=	$(BUILTINS)/builtins.c \
			$(BUILTINS)/fg.c \
			$(BUILTINS)/bg.c \
			$(BUILTINS)/jobs.c \
			$(BUILTINS)/robert.c \
			$(BUILTINS)/cd.c \
			$(BUILTINS)/echo.c \
			$(BUILTINS)/env.c \
			$(BUILTINS)/setenv.c \
			$(BUILTINS)/unsetenv.c \
			$(BUILTINS)/exit.c \
			$(BUILTINS)/history.c \
			$(BUILTINS)/alias.c \
			$(BUILTINS)/source.c \
			$(BUILTINS)/clear.c

SRCLINE		=	$(PATHLINE)main.c \
			$(PATHLINE)read_cmd.c \
			$(PATHLINE)gere_keyboard.c \
			$(PATHLINE)decal_string.c \
			$(PATHLINE)view.c \
			$(PATHLINE)suppression.c \
			$(PATHLINE)gere_control.c \
			$(PATHLINE)start_end_cmd.c \
			$(PATHLINE)clear.c \
			$(PATHLINE)control_y.c \
			$(PATHLINE)control_k.c \
			$(PATHLINE)update_pos.c \
			$(PATHLINE)refresh_view.c \
			$(PATHLINE)gere_window.c \
			$(PATHLINE)globb.c \
			$(PATHLINE)return_globb_str.c \
			$(PATHLINE)view_globb.c \
			$(PATHLINE)completation.c \
			$(PATHLINE)plus_completation.c \
			$(PATHLINE)gere_control_u.c \
			$(PATHLINE)return_string.c \
			$(PATHLINE)add_caractere.c \

SRCLIBLINE	=	$(LIBLINE)/str_cmp.c \
			$(LIBLINE)/my_putstr.c \
			$(LIBLINE)/my_memset.c

SRCTERMCAP	=	$(PATHTERMCAP)coordone.c \
			$(PATHTERMCAP)mod_raw.c \
			$(PATHTERMCAP)curseur.c \
			$(PATHTERMCAP)get_pos_curser.c \
			$(PATHTERMCAP)clear.c \
			$(PATHTERMCAP)verif_env.c \
			$(PATHTERMCAP)init_termcap.c \
			$(PATHTERMCAP)apply_termcap.c \
			$(PATHTERMCAP)print_termcap.c \
			$(PATHTERMCAP)read_tty.c

OBJ		=	$(SRC:.c=.o) \
			$(SRCBUILTINS:.c=.o) \
			$(ENV:.c=.o) \
			$(SRCLINE:.c=.o) \
			$(SRCLIBLINE:.c=.o) \
			$(SRCTERMCAP:.c=.o) \
			$(SRCRED:.c=.o) \
			$(SRCGLOBB:.c=.o)

$(NAME):		$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIBS)

all:			$(NAME)

clean:
			$(RM) -f $(OBJ)

fclean:			clean
			$(RM) -f $(NAME)

re:			fclean all
