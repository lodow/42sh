/*
** unsetenv.c for unsetenv in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Feb 21 14:55:14 2013 remi robert
** Last update Thu Mar  7 19:53:46 2013 remi
*/

#include "my_func.h"

void	free_elem_for_list(t_list **pcourant)
{
  if ((*pcourant)->tab != NULL)
    free((*pcourant)->tab);
  free(*pcourant);
}

t_list	**suppr_elem_list(t_list **ptete, t_list **pcourant)
{
  if ((*pcourant)->back == NULL && (*pcourant)->next == NULL)
    {
      free_elem_for_list(pcourant);
      return (NULL);
    }
  if ((*pcourant)->back == NULL)
    {
      *ptete = (*pcourant)->next;
      (*ptete)->back = NULL;
      free_elem_for_list(pcourant);
      return (ptete);
    }
  if ((*pcourant)->next == NULL)
    {
      (*pcourant)->back->next = NULL;
      free_elem_for_list(pcourant);
      return (ptete);
    }
  (*pcourant)->back->next = (*pcourant)->next;
  (*pcourant)->next->back = (*pcourant)->back;
  free_elem_for_list(pcourant);
  return (ptete);
}

int		fct_unsetenv(t_list **ptete, t_cmd *cmd)
{
  t_list	*pcourant;
  int		ret;

  if (*ptete == NULL || cmd == NULL ||
      cmd->cmd[0] == NULL || cmd->cmd[1] == NULL)
    return (0);
  pcourant = *ptete;
  while (pcourant != NULL &&
	 (ret = str_cmp_env(pcourant->tab, cmd->cmd[1])) != 1)
    {
      if (pcourant == NULL)
	return (0);
      pcourant = pcourant->next;
    }
  if (ret == 1)
    ptete = suppr_elem_list(ptete, &pcourant);
  return (1);
}
