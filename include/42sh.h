/*
** 42sh.h for 42sh in /home/maxime/Bureau/projet/actu/42sh/include
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:39:43 2013 maxime lavandier
** Last update Fri Mar 29 11:00:59 2013 maxime lavandier
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
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <dirent.h>
# include "get_file.h"

# define NB_BUILTINS 10

# define PIPE_READ 0
# define PIPE_WRITE 1

# define SETFLAG(x, y) ((x) |= (y))
# define UNSETFLAG(x, y) ((x) &= ~(y))
# define SWITCHFLAG(x, y) ((x) ^= (y))
# define GETFLAG(x, y) ((x) & (y))
# define FLAGPOS(x) (1 << (x))

# define GET_USER_LINE get_next_line(0)

#define FGRP_RUNNING 0
#define FGRP_TERMINATED 1
#define FGRP_FORGROUND 2

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

typedef struct	s_grp
{
  t_pid		pid;
  t_fds		fd;
  char		*line;
  t_cmd		**cmds;
  int		flags;
}		t_grp;

typedef struct	s_func_ptr
{
  char		*str;
  void		*func;
}		t_func_ptr;

typedef struct	s_sh
{
  t_func_ptr	builtins[NB_BUILTINS];
  t_pid		pid;
  char		**path;
  char		**env;
  char		**alias_tab;
  t_grp		**process_group;
  int		signal;
}		t_sh;

/*
** Builtins
*/
int	is_cmd_a_builtin(t_sh *shell, t_cmd *cmd, int exec);
void	init_builtins(t_sh *shell);
void	builtin_exit(t_sh *shell, t_cmd *cmd);
void	builtin_cd(t_sh *shell, t_cmd *cmd);
void	builtin_env(t_sh *shell, t_cmd *cmd);
void	builtin_unsetenv(t_sh *shell, t_cmd *cmd);
void	builtin_setenv(t_sh *shell, t_cmd *cmd);
void	builtin_echo(t_sh *shell, t_cmd *cmd);
void	builtin_robert(t_sh *shell, t_cmd *cmd);
void	builtin_fg(t_sh *shell, t_cmd *cmd);
void	builtin_bg(t_sh *shell, t_cmd *cmd);
void	builtin_jobs(t_sh *shell, t_cmd *cmd);

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
void	free_ptr_tab(void **tab);
void	**concat_ptr_tab(void **tab1, void **tab2);

/*
** Stc
*/
int	my_strlen(char *str);
void	my_putstr(char *str, int fd, int strlen);
void	my_strncpy(char *dest, char *src, int n);
char	*my_strdup(char *str);
int	is_in_str(char c, char *str);
int	my_strncmp(char *s1, char *s2, int n);
void	swap_ptr(void **ptr1, void **ptr2);
void	tr_str(char *str, char in, char to);
char	*my_uint_strbase(unsigned int nb, char * base);
int	my_getnbr(char *str);

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
void	update_jobs_status(t_sh *shell);
int	group_process_group(t_grp *pipeline);
void	set_forground_pgrp(pid_t pgid);
void	set_forground_process_g(t_sh *shell, t_grp *grp);
t_grp	*get_forground_grp(t_sh *shell);

/*
** Wait and childs termination
*/
void	wait_all_jobs(t_sh *shell, t_grp **jobtab);
void	wait_no_fg_grp(t_sh* shell);

/*
** User funcs
*/
void	user_loop(t_sh *shell);
void	parse_user_cmd(t_sh *shell, char *line);
void	prompt(t_sh *shell);

/*
** Pipes
*/
int	exec_a_pipe(t_sh *shell, t_grp *grp);

/*
** Env var
*/
char	*check_vars_in_str(char *str, char **envp);

/*
** Commands
*/
t_grp	*create_n_process_group(t_sh *shell, char *lign);
t_cmd	*create_n_cmd(t_sh *shell, char *lign);
char	*exec_full_path(char *exec, char **paths);
int	exec_process_group(t_sh *shell, t_grp *grp);
void	exec_process(t_cmd *cmd, t_fds *fd, t_sh *shell, t_grp *grp);
void	free_process_group(t_grp *grp);
int	is_grp_exec(t_sh *shell, t_grp *grp);

/*
** Fds
*/
void	init_stdfd_t_def_val(t_fds *fds, int stdin, int stdout, int stderr);
void	close_fds(t_fds *fd);

/*
** Alias
*/
void	alias_replace(char ***argv, char **alias);

/*
** Exit
*/
void	my_exit(int value);

#endif
