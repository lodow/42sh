/*
** misc.c for misc in /home/dellam_a/Projet/SVN/minishell1-2017-dellam_a
** 
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
** 
** Started on  Wed Feb  6 13:37:07 2013 Adrien dellamaggiora
** Last update Thu Mar  7 16:11:04 2013 Adrien
*/

#include "my.h"

int	findinstr(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

char	*erasetab(char *str)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  j = 0;
  if ((res = malloc(my_strlen(str) + 1)) == NULL)
    exit(0);
  while (str[i] != 0)
    {
      if (str[i] == '\t')
	res[j] = ' ';
      else
	res[j] = str[i];
      i++;
      j++;
    }
  res[j] = 0;
  free(str);
  return (res);
}

void    my_exec(t_cmd *sh, int j)
{
  int	i;

  i = 0;
  sh->opt = my_str_to_wordtab(sh->cmdpi[j], ' ');
  while (sh->path[i] != NULL)
    {
      sh->s_exec = fullpath(sh->path[i], sh->opt[0]);
      if (access(sh->s_exec, F_OK | X_OK) == 0)
	{
	  my_fork(sh->s_exec, sh, sh->cmdpi[j + 1]);
	  free(sh->s_exec);
	  freetab(sh->opt);
	  return ;
	}
      else if (access(sh->opt[0], F_OK | X_OK) == 0)
	{
	  my_fork(sh->opt[0], sh, sh->cmdpi[j + 1]);
	  freetab(sh->opt);
	  free(sh->s_exec);
	  return ;
	}
      free(sh->s_exec);
      i++;
    }
  freetab(sh->opt);
}
