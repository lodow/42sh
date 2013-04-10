/*
** redir.c for minishell in /home/maxime/Bureau/projet/actu/minishel2
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Thu Mar  7 23:13:40 2013 maxime lavandier
** Last update Wed Apr 10 10:04:26 2013 remi robert
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_list.h"
#include "str_to_wordtab.h"

char	*nextspace(char *str)
{
  int	i;

  i = 0;
  if (str == 0)
    return (0);
  while (str[i] == ' ')
    i++;
  return(&(str[i]));
}

char		*redir_debut(char *com, t_pipe *pipe)
{
  char		**tab;
  int		fd;

  tab = str_to_wordtab(com, '>', pipe->ptete, -1);
  if (tab[0] == 0 || tab[1] == 0)
    {
      return (com);
    }
  if ((fd = open(nextspace(tab[1]), O_RDONLY)) == -1)
    return (com);
  dup2(fd, 0);
  return (tab[0]);
}

char		*redir_over(char **tab, char *com)
{
  int		fd;
  mode_t	flag;

  flag = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  if ((fd = open(nextspace(tab[1]), O_WRONLY | O_CREAT | O_TRUNC, flag)) == -1)
    return (com);
  dup2(fd, 1);
  return (tab[0]);
}

char		*redir_fin(char *com, t_pipe *pipe)
{
  char		**tab;
  int		fd;
  int		i;
  mode_t	flag;

  tab = str_to_wordtab(com, '>', pipe->ptete, -1);
  if (tab[0] == 0 || tab[1] == 0)
    return (redir_debut(com, pipe));
  while (com[i] != 0)
    {
      if (com[i] == '>' && com[i + 1] == '>')
	{
	  flag = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	  if ((fd = open(nextspace(tab[1]), O_WRONLY |
			 O_CREAT | O_APPEND, flag)) == -1)
	    return (com);
	  dup2(fd, 1);
	  return (tab[0]);
	}
      else if (com[i] == '>')
	return(redir_over(tab, com));
      i++;
    }
  return (com);
}
