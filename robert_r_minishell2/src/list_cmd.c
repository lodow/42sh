/*
** list_pipe.c for list_pipe in /home/remi/Projet/recode_minishel/test_pipe
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Feb 14 20:03:18 2013 remi robert
** Last update Sat Mar  9 11:46:30 2013 remi
*/

#include "my_func.h"

char	**epure_str(char **cmd)
{
  int	indice;
  int	indice2;

  indice = 0;
  if (cmd == NULL)
    return (cmd);
  my_putstr(JAUNE);
  while (cmd[indice] != NULL)
    {
      if (cmd[indice][0] == ' ')
	{
	  my_putstr("0");
	  while (cmd[indice][indice2 + 1] != '\0')
	    {
	      cmd[indice][indice2] = cmd[indice][indice2] + 1;
	      indice2 = indice2 + 1;
	    }
	  cmd[indice][indice2] = '\0';
	}
      indice = indice + 1;
    }
  my_putstr(REZ);
  return (cmd);
}

void	add_to_list_cmd(t_cmd **ptete, char **cmd)
{
  t_cmd	*elem;
  t_cmd	*pcourant;

  if (*ptete == NULL)
    {
      if ((*ptete = malloc(sizeof(t_cmd))) == NULL)
	return ;
      (*ptete)->next = NULL;
      (*ptete)->back = NULL;
      (*ptete)->cmd = cmd;
      return ;
    }
  if ((elem = malloc(sizeof(t_cmd))) == NULL)
    return ;
  pcourant = *ptete;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  elem->cmd = epure_str(cmd);
  elem->next = NULL;
  elem->back = pcourant;
  pcourant->next = elem;
}
