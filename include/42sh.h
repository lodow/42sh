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

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define NB_BUILTINS 10

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
  int		return_value;
  t_fds		fd;
  t_pid		pid;
}		t_cmd;

typedef struct	s_pipe
{
  t_fds		fd;
  t_pid		pid;
  char		*line;
  t_cmd		**cmds;
  int		running;
}		t_pipe;

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
  t_pipe	**pipes;
  t_pipe	*forground;
}		t_sh;

/*
** Builtins
*/
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
void	**add_ptr_t_tab(void **tab, void *add);
void	free_ptr_tab(void **tab);

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

#endif
