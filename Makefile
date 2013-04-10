##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Wed Apr 10 08:57:41 2013 remi robert
##

INVOCATION=	gcc

SRCPATH	=	src/

BUILTINS=	src/builtins/

PATHLINE=	edition_line/

PATHENV	=	src/env/

LIBLINE	=	edition_line/lib/

PATHTERMCAP=	edition_line/termcap/

SRC	= 	$(SRCPATH)main.c				\
		$(SRCPATH)stc.c					\
		$(SRCPATH)str.c					\
		$(SRCPATH)my_uint64_t_strbase.c			\
		$(SRCPATH)tr_str.c				\
		$(SRCPATH)shell.c				\
		$(SRCPATH)str_to_wordtab.c			\
		$(SRCPATH)signal.c				\
		$(SRCPATH)job.c					\
		$(SRCPATH)jobs_forground.c			\
		$(SRCPATH)is_grp_exec.c				\
		$(SRCPATH)fd.c					\
		$(SRCPATH)swap_ptr.c				\
		$(SRCPATH)alias.c				\
		$(SRCPATH)parse_cmd.c				\
		$(SRCPATH)process_group.c			\
		$(SRCPATH)exec_process.c			\
		$(SRCPATH)tty.c					\
		$(SRCPATH)pipe.c				\
		$(SRCPATH)cmd.c					\
		$(SRCPATH)wait.c				\
		$(SRCPATH)cmd_full_path.c			\
		$(SRCPATH)ptr_tab.c				\
		$(SRCPATH)get_next_line.c			\
		$(SRCPATH)variable.c				\
		$(SRCPATH)my_getnbr.c				\
		$(SRCPATH)my_putchar.c				\
		$(SRCPATH)clean_tab.c				\
		$(SRCPATH)my_exit.c				\

ENV	=	$(PATHENV)env.c					\

SRCBUILTINS=	$(BUILTINS)builtins.c				\
		$(BUILTINS)fg.c					\
		$(BUILTINS)bg.c					\
		$(BUILTINS)jobs.c				\
		$(BUILTINS)robert.c				\
		$(BUILTINS)cd.c					\
		$(BUILTINS)echo.c				\
		$(BUILTINS)env.c				\
		$(BUILTINS)setenv.c				\
		$(BUILTINS)unsetenv.c				\
		$(BUILTINS)exit.c				\

SRCLINE	=	$(PATHLINE)main_line.c				\
		$(PATHLINE)add_caractere.c			\
		$(PATHLINE)return_string.c			\
		$(PATHLINE)read_cmd.c				\
		$(PATHLINE)free.c				\
		$(PATHLINE)view_string.c			\
		$(PATHLINE)get_len_string_with_pos.c		\
		$(PATHLINE)gere_keyboard.c			\
		$(PATHLINE)suppression.c			\
		$(PATHLINE)gere_control.c			\
		$(PATHLINE)gere_buff_copy.c			\
		$(PATHLINE)gere_buff_feature.c			\
		$(PATHLINE)set_pos_curser.c			\
		$(PATHLINE)init_struct_param.c			\
		$(PATHLINE)print_prompt.c			\

SRCLIBLINE=	$(LIBLINE)str_cmp_env.c				\
		$(LIBLINE)str_cmp.c				\
		$(LIBLINE)my_memset.c				\
		$(LIBLINE)my_putstr.c				\

SRCTERMCAP=	$(PATHTERMCAP)ecrase_text.c			\
		$(PATHTERMCAP)coordone.c			\
		$(PATHTERMCAP)mod_raw.c				\
		$(PATHTERMCAP)curseur.c				\
		$(PATHTERMCAP)get_pos_curser.c			\
		$(PATHTERMCAP)clear.c				\
		$(PATHTERMCAP)dl_current_pos.c			\

OBJ	=	$(SRC:.c=.o)

OBJB	=	$(SRCBUILTINS:.c=.o)

OBJENV	=	$(ENV:.c=.o)

OBJLINE	=	$(SRCLINE:.c=.o)

OBJLIBLINE=	$(SRCLIBLINE:.c=.o)

OBJTERMCAP=	$(SRCTERMCAP:.c=.o)

ALLOBJ	=	$(OBJ) $(OBJB) $(OBJENV) $(OBJLIBLINE) $(OBJTERMCAP) $(OBJLINE)

NAME	=	robertSH

CFLAGS	=	-g -Wall -Wfloat-equal -Wmissing-include-dirs \
		-Wclobbered -Wempty-body -Wignored-qualifiers \
		-Wmissing-field-initializers -Wmissing-parameter-type \
		-Wold-style-declaration -Woverride-init -Wsign-compare \
		-Wtype-limits -Wuninitialized -ltermcap

all:		$(NAME)

$(NAME):	$(ALLOBJ)
		$(INVOCATION) $(ALLOBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(ALLOBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
