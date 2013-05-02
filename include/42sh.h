/*
** 42sh.h for 42sh in /home/maxime/Bureau/projet/actu/42sh/include
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:39:43 2013 maxime lavandier
** Last update Tue Apr 16 15:20:39 2013 maxime lavandier
*/

#ifndef		SH42_H
# define		SH42_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>
# include <glob.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <dirent.h>
# include "get_file.h"
# include "my_func.h"

# define NB_BUILTINS 14
# define NB_CONFFUNC 2

# define PIPE_READ 0
# define PIPE_WRITE 1

# define ECHO_5(y)	(y == 't' ? '\t' : y == 'v' ? '\v' : -1)
# define ECHO_4(y)	(y == 'n' ? '\n' : y == 'r' ? '\r' : ECHO_5(y))
# define ECHO_3(y)	(y == 'e' ? '\e' : y == 'f' ? '\f' : ECHO_4(y))
# define ECHO_2(y)	(y == 'b' ? '\b' : y == 'c' ? -2 : ECHO_3(y))
# define ECHO_1(y)	(y == '\\' ? '\\' : y == 'a' ? '\a' : ECHO_2(y))

# define SETFLAG(x, y) ((x) |= (y))
# define UNSETFLAG(x, y) ((x) &= ~(y))
# define SWITCHFLAG(x, y) ((x) ^= (y))
# define GETFLAG(x, y) ((x) & (y))
# define FLAGPOS(x) (1 << (x))


# define EXIT_F_POS 31
# define MEXIT GETFLAG(shell->beepbeepexit, FLAGPOS(EXIT_F_POS))

/*
** Groups transition flags
*/
# define GRP_TRANS_NONE 0
# define GRP_TRANS_AND 1
# define GRP_TRANS_OR 2

/*
** Jobs flags
*/
# define FGRP_RUNNING 0
# define FGRP_TERMINATED 1
# define FGRP_FORGROUND 2

/*
** Redir defines
*/
# define REDI_FRIGHT 0666
# define REDI_R 3
# define REDI_DR 4
# define REDI_L 1
# define REDI_DL 2

typedef struct	s_fds
{
  int		stdin;
  int		stdout;
  int		stderr;
}		t_fds;

typedef struct	s_pid
{
  pid_t		sid;
  pid_t		pid;
  pid_t		pgid;
}		t_pid;

typedef struct	s_cmd
{
  char		*line;
  char		**argv;
  char		*cmd_fpath;
  int		return_value;
  t_pid		pid;
}		t_cmd;

typedef struct	s_redirection
{
  int		end;
  int		red_g;
  int		red_b;
  char		*file_b;
  char		*file_g;
}		t_redirection;

typedef struct	s_grp
{
  int		nb_red;
  t_pid		pid;
  t_fds		fd;
  char		*line;
  t_cmd		**cmds;
  int		flags;
  t_redirection	*redirection;
  int		transition;
  char		*transition_line;
}		t_grp;

typedef struct	s_func_ptr
{
  char		*str;
  void		*func;
}		t_func_ptr;

typedef struct	s_sh
{
  t_history	*history;
  t_func_ptr	builtins[NB_BUILTINS];
  t_pid		pid;
  t_param	param;
  char		**path;
  char		**env;
  char		**alias_tab;
  t_grp		**process_group;
  int		signal;
  int		beepbeepexit;
}		t_sh;

/*
** Builtins
*/
int	is_cmd_a_builtin(t_cmd *cmd, t_fds *fd, t_sh *shell, int exec);
void	init_builtins(t_sh *shell);
void	builtin_exit(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_cd(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_env(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_unsetenv(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_setenv(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_echo(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_robert(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_fg(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_bg(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_jobs(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_history(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_alias(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_source(t_cmd *cmd, t_fds *fd, t_sh *shell);
void	builtin_clear(t_cmd *cmd, t_fds *fd, t_sh *shell);


/*
** History
*/
int		load_history_f_file(char *line, t_sh *shell);
int		view_history(char *path, char **argv, t_sh *shell);
void		rm_history_d(t_history **ptete, int pos);
t_history	*suppr_elem_list(t_history **ptete, t_history **pcourant);

/*
** Env
*/
char	*get_envvar(char *var, char **env);
char	**cpy_env(char **envp);
void	rm_env(char **envp, char *env);
char	**add_change_env(char **env, char *var, char *value);

/*
** Ptr tab
*/
void	rm_ptr_f_tab(void **tab, void *ptr);
void	**add_ptr_t_tab(void **tab, void *add);
void	free_ptr_tab(void **tab, void (*f)(void *ptr));
void	**concat_ptr_tab(void **tab1, void **tab2);

/*
** Stc
*/
void	my_putchar(char c);
int	my_strlen(char *str);
void	my_putstr(const char *str, int fd, int strlen);
void	my_strncpy(char *dest, char *src, int n);
char	*my_strdup(char *str);
int	is_in_str(char c, char *str);
int	my_strncmp(char *s1, char *s2, int n);
void	swap_ptr(void **ptr1, void **ptr2);
void	tr_str(char *str, char in, char to);
char	*my_uint_strbase(unsigned int nb, char * base);
int	my_getnbr(char *str);
void	my_strncpy_force(char *str1, char *str2, int size);
void	del_slash_quote(char **tab);
char	*my_stradd(char *str, char *add, int size_add);

/*
** Str to wordtab
*/
char	**str_to_wordtab(char *str, char *delim, char inibiteur);
void	rm_empty_str_f_tab(char **tab);

/*
** Signals
*/
t_sh	*get_sh_info(t_sh *sh);
void	sig_handler(int sig);
void	call_signal_func(t_sh *shell, int chld_sig);

/*
** Jobs
*/
void	no_fg_jobs_status(t_sh *shell);
int	group_process_group(t_grp *pipeline);
void	set_forground_pgrp(pid_t pgid);
void	set_forground_process_g(t_sh *shell, t_grp *grp);
t_grp	*get_forground_grp(t_sh *shell);

/*
** Wait and childs termination
*/
void	wait_all_jobs(t_sh *shell);
void	wait_no_fg_grp(t_sh* shell);
t_cmd	*cmd_f_pid(int pid, t_sh *shell);

/*
** User funcs
*/
void	user_loop(t_sh *shell);
void	parse_user_cmd(t_sh *shell, char *line, int def_fdout);
void	prompt(t_sh *shell);

/*
** Pipes
*/
char	*type_next_and_or(char *line, int *type);
int	exec_a_pipe(t_sh *shell, t_grp *grp);

/*
** Error
*/
void	my_perror(char *str);

/*
** Env var
*/
char	*get_envvar(char *var, char **env);
char	*check_vars_in_str(char *str, char **envp);
void	replace_var_in_argv(char **argv, char **envp);

/*
** Commands
*/
int	exec_next_grp(t_grp *grp, t_sh *shell);
void	rm_all_terminated_grp(t_sh *shell);
int	global_group_ret_status(t_grp *grp);
t_grp	*create_n_process_group(t_sh *shell, char *lign);
t_cmd	*create_n_cmd(t_sh *shell, char *lign);
char	*exec_full_path(char *exec, char **paths);
int	exec_process_group(t_sh *shell, t_grp *grp);
void	cmd_execution(t_cmd *cmd, t_fds *fd, t_sh *shell);
int	exec_process(t_cmd *cmd, t_fds *fd, t_sh *shell,
                 int (*f)(char *cmd, char **argv, t_sh *shell));
void	free_process_group(t_grp *grp);
int	is_grp_exec(t_sh *shell, t_grp *grp);

/*
** Fds
*/
void	init_stdfd_t_def_val(t_fds *fds, int stdin, int stdout, int stderr);
void	close_fds(t_fds *fd);

/*
** Conf file
*/
void	store_history_f(t_sh *shell, int fd);
int	new_conf_set(char *str, t_sh *shell);
void	store_conf_file(char *filename, t_sh *shell,
                      void (*f)(t_sh *shell, int fd));
void	load_conf_file(char *filename, t_sh *shell,
                     int (*f)(char *line, t_sh *shell));
void	alias_replace(char ***argv, char **alias);

/*
** Exit
*/
void	my_exit(int value);
void	exit_shell(t_sh *shell);

/*
** detect_type_redirection
*/
int	return_type_char(char *);
void	return_type_redirection(char *, int *, int *);
char	*find_name_redirection(int, char *);
char	*return_file_redir(char *, int, int);

/*
** redirection
*/
char	*parse_redirection(t_grp *, char *, int *);
void	rempl_fd_process(t_redirection *, t_grp *);
int	find_redirection(char **, char *);
int	rempl_red(char **, t_redirection *);
void	rempl_file_redirection(char *, char *);
void	rempl_new_lign_cmd(char *, char **, int, int);
char	*reform_lign(char **);

/*
** Backquotes
*/
char	*check_and_load_backquote(char *line, t_sh *shell);

/*
** my_str_to_wordtab
*/
void	del_slash_quote(char **);
void	my_strncpy_force(char *, char *, int);

char	**get_path(char **envp);

/*
** Glob
*/
void	expand_reg_epx_on_argv(char ***argv);
char	**expand_reg_exp(char *regexp);

#endif
