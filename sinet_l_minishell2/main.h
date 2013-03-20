/*
** main.h for main in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Feb 15 10:58:17 2013 luc sinet
** Last update Sat Mar  9 13:32:54 2013 luc sinet
*/

#ifndef SHELL_H_
# define SHELL_H_

#include <stdlib.h>
#include <stdio.h>
#include "nb.h"
#include "str.h"
#include "my_str_to_wordtab.h"

typedef struct	s_sh
{
  char		**menv;
  char		**path;
  char		**alias;
  char		*sign[5];
  char		*prompt;
  char		f_alias;
  char		run;
  int		fa;
  int		sa;
  int		rv;
  int		*pid;
  int		cpid;
  int		old_fd;
  int		nb_pipe;
}		t_sh;

char	*get_prompt(t_sh *spt, char **env);
char	*format_cmd(char *cmd);
int	b_cd(t_sh *spt, char **cmd);
int	b_exit(t_sh *spt, char **cmd);

#endif
