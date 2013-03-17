/*
** my_fun.c for my_fun	 in /home/remi/Projet/minishell/new_shell/env
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 14:13:53 2013 remi robert
** Last update Sat Mar  9 12:55:05 2013 remi
*/

#ifndef MY_FUNC_H_
# define MY_FUNC_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "couleur.h"

typedef struct	s_echo
{
  int		option_n;
  int		option_e;
  int		option_ee;
}		t_echo;

typedef struct	s_cmd
{
  struct s_cmd	*next;
  struct s_cmd	*back;
  char		path[2048];
  char		**cmd;
  int		fd[2];
  int		type;
}		t_cmd;

typedef struct	s_pipe
{
  int		fd_file_rg;
  int		fd_file_rd;
  int		indice;
  t_cmd		*ptemp;
  int		pid[2048];
  int		nb_pipe;
}		t_pipe;

typedef struct	s_list
{
  struct s_list	*next;
  struct s_list	*back;
  char		*tab;
}		t_list;

/*
** ascii_art.c
*/
void		print_ascii_art(void);

/*
** copy_inter_buff.c
*/
void		copy_inter_buff(char *, char *);

/*
** file_cmd.c
*/
void		open_file_cmd(int *, t_cmd **, int, int);
void		close_file_cmd(int *);

/*
** alias.c
*/
int		rez_buff_fix(char *);
int		return_name_alias(char *, char *);
int		return_nb_param_cmd(char **);
int		return_indice_begin_alias(char *);
void		rempl_alias_cmd(t_cmd **, char *, char **, char **);
int		check_alias(char *, t_cmd **, t_list *, int);
int		detect_alias(t_cmd **, t_list *);

/*
** interpretation_string.c
*/
void		detect_string(char *, char *, int *);
void		interpretation_string(char *);

/*
** rm_first_lm_list.c
*/
int		number_elem_history(t_list **);
void		rm_first_lm_list(t_list **);

/*
** return_path_conf.c
*/
char		*return_path_conf(t_list *);

/*
** print_color.c
*/
void		print_couleur(int);
void		print_font_couleur(int);

/*
** test_type_cmd.c
*/
int		test_type_cmd(int);

/*
** list.c
*/
char		*str_dup(char *);
void		add_to_list(t_list **, char *);

/*
** epure_str.c
*/
char		*epure_cmd(char *);

/*
** reformat_buff_cmd.c
*/
void		reformat_buff_cmd(char *);

/*
** interpretation_env.c
*/
void		return_indice_pos_env(char *, char *, int *);
void		interpretation_env(char *, t_list *);

/*
** init_shell.c
*/
void		init_shell(t_list **);
int		ignore_space_buff(char *, int);
void		finalise_var_env(char *, t_list **, int);
void		cut_export_format(char *, t_list **);

/*
** get_next_line.c
*/
char		*get_next_line(int);
char		*return_str(char *, int *);
void		decale_buff(char *, int);

/*
** my_str_isprintable.c
*/
int		my_str_isprintable(char *);

/*
** prompt.c
*/
void		prompt(t_list *);
int		exec_color(char *, int, int);

/*
** parser_instruction.c
*/
int		detect_pipe(t_cmd *);
int		detect_redirection(t_cmd *, int);
char		*return_name_file_redirection(t_cmd *, int);
int		increment_pos(t_cmd **);
void		exec_simple_command(t_cmd **, t_list *, int, int);

/*
** loop_parser_instruction.c
*/
void		loop_exec(t_cmd **, t_list **, t_cmd *, t_list **);
void		parser_instruction(t_cmd *, t_list **, t_list **);

/*
** my_putstr.c
*/
void		my_putchar(char);
void		my_putstr(char *);

/*
** run_loop.c
*/
void		run_loop(t_list *);

/*
** my_str_to_wordtab.c
*/
char		**str_to_wordtab(char *, char *);

/*
** str_assemble.c
*/
char		*str_assemble(char *, char *, char);

/*
** detect_fct.c
*/
int		exec_fonction(t_list **, t_cmd **, int, t_list **);
int		detect_fct(t_list **, t_cmd **, t_list **);

/*
** my_getnbr.c
*/
int		depassement(int);
int		get_number(char *, int , int , int);
int		my_getnbr(char *);

/*
** read_cmd.c
*/
void		detect_type_cmd(char *);
t_cmd		*rempl_cmd(char *);
t_cmd		*read_cmd(t_list *, t_list **);

/*
** detect_type_op.c
*/
t_cmd		*detect_type_op(t_cmd *, char *);
int		number_cmd(char *, int, int);
int		return_op(char);
void		init_tab(char *, int);
void		rempl_buff_op(char *, char *);

/*
** pipe.c
*/
void		init_all_cmd(t_cmd **, t_pipe *);
void		close_all_fd(t_cmd *, int, t_pipe *);
void		wait_all(t_pipe *);
int		number_pipe(t_cmd *);

/*
** exec_pipe.c
*/
int		first_pipe(t_cmd **, t_list *, t_pipe *, int);
int		inter_pipe(t_cmd **, t_list *, t_pipe *);
int		last_pipe(t_cmd **, t_list *, t_pipe *, int);
void		exec_pipe(t_cmd **, t_list *);

/*
** char_env.c
*/
char		**return_env(t_list *);
void		rempl_env(t_list **, char **);
int		nb_elem_env(t_list *);

/*
** redirection.c
*/
int		open_file(int, char *, int *);

/*
** my_str_to_wordtab.c
*/
int		test_carac(char, char *);
int		return_number_word(char *, char *, int);
void		interval_word(int *, int *, char *, char *);
char		*return_word(char *, int, int);
char		**str_to_wordtab(char *, char *);

/*
** find_cmd.c
*/
int		find_cmd(t_cmd *, t_list *);
void		print_error(char *, int);
void		write_path(t_cmd *, char *);
int		access_path(char *);
char		**return_env_list(t_list *);

/*
** gere_signal.c
*/
void		get_signal(int);
int		gere_signal(void);

/*
** fin_exec_other_path.c
*/
int		find_exec_other_path(t_cmd **, t_list *);

/*
** parser_instruction.c
*/
char		*return_name_file_redirection_gauche(t_cmd *);

/*
** builtins
*/
int		fct_exit(t_list **, t_cmd *);
int		fct_env(t_list **, t_cmd *);
int		fct_setenv(t_list **, t_cmd *);
int		fct_unsetenv(t_list **, t_cmd *);
int		fct_cd(t_list **, t_cmd *);
void		fct_cd_option(t_list **);
char		*return_current_pwd(t_list *, char *);
void		delete_old_pwd(t_list **);
t_list		**suppr_elem_list(t_list **, t_list **);
void		fct_cd_moins(t_list **);
void		ecrase_pwd(t_list **, char *);
void		add_pwd(t_list **, char *);
void		trunck_pwd(t_list **);
t_list		*return_env_pwd(t_list **);
void		fct_cd_home(t_list **);
int		fct_history(t_list **, t_cmd **);
char		*number_to_char(int, char *);
void		view_hitory(t_list **, t_cmd *);
int		fct_echo(t_list **, t_cmd *);
void		print_string_echo(char *, t_echo *);
void		print_string_echo_option_n(char *, int);
void		init_struct_echo(t_echo *);
void		cut_str_arg(char *, t_echo *);
void		parsing_option_echo(char **, t_echo *);

/*
** free.c
*/
void		free_env(t_list *);
void		free_tab_cmd(char **);
void		free_list_cmd(t_cmd *);

/*
** list_cmd.c
*/
void		show_list(t_cmd *);
char		**epure_str(char **);
void		add_to_list_cmd(t_cmd **, char **);

/*
** str_cmp.c
*/
int		my_strlen(char *);
int		str_cmp(char *, char *);
int		str_cmp_env(char *, char *);

#endif /* MY_FUNC_H_ */
