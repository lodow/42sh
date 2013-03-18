/*
** my.h for mysh in /home/dellam_a//Projet/System Unix/minishell
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Dec 10 10:01:20 2012 adrien dellamaggiora
** Last update Thu Mar  7 15:06:51 2013 Adrien
*/

#ifndef MY_H_
# define MY_H_

# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct	s_cmd
{
  char		*s_exec;
  char		*cmd;
  char		*tmps;
  char		**cmdpi;
  char		**path;
  char		**env;
  char		**opt;
  int		*pid;
  int		fdin;
}		t_cmd;

/*
** main.c
*/

int		findindir(char *str, t_cmd *sh);
char		**cmd(char *str, t_cmd *sh);
char		**parse(t_cmd *sh);

/*
** cd .c
*/

char		**my_cd(char *str, char **path, char **env);
char		**executable(char *str, char **path, char **env);
void		freetab(char **tab);
void		get_signal();
char		*sup_space(char *str);

/*
** env.c 
*/

char		*my_dup(char *str);
char		*my_strdup(char *str);
char		**cpy_env(char **env);
char		**set_env(char *str, char **path, char **env);
char		**unset_env(char *str, char **path, char **env);

/*
** handle_cmd.c
*/

char		**inittab(char **tab);
char		**my_exit(char *str, char **path, char **env);
char		**handle_cmd(char *str, char **path, char **env);

/*
** misc.c
*/

int		findinstr(char *str, char c);
char		*erasetab(char *str);
void		my_exec(t_cmd *sh, int j);

/*
** my_strfunc.c
*/

int		my_strncmp(char *str1, char *str2, int n);
char		**parsepath(char **env);
char		*fullpath(char *path, char *str);
char		**printenv(char *str, char **path, char **env);

/*
** my_str_to_wordtab.c
*/

char		**my_tabcpy(char **tab, char *str, char delim);
int		nbdelim(char *str, char delim);
char		**my_str_to_wordtab(char *str, char delim);

/*
** pipe.c
*/

int		check_pipe(char *str);
int		check_cmd(char **cmd, char **path);
void		my_fork(char *str, t_cmd *sh, char *cmd);

/*
** print.c
*/

void		my_putchar(char c);
void		my_putstr(char *str);
int		my_strcmp(char *str1, char *str2);
int		my_strlen(char *str);

/*
** pid.c
*/

void		my_wait(int *pid);
int		*add_pid(int *pid, int newpid);

/*
** redirect.c
*/

int		check_redir(char **opt);
int		my_redirec(int type, char **opt);
char		**rm_redir(char **opt);
char		*get_redirname(int type, char **opt);

#endif
