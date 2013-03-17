/*
** unsetenv.c for unsetenv in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Feb 21 14:55:14 2013 remi robert
** Last update Thu Feb 21 15:05:30 2013 remi robert
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

void		fct_unsetenv(t_list **ptete, char *str)
{
  t_list	*pcourant;

  if (*ptete == NULL || str == NULL)
    return ;
  pcourant = *ptete;
  while (pcourant->next != NULL && str_cmp_env(pcourant->tab, str) != 1)
    {
      if (pcourant == NULL)
	return ;
      pcourant = pcourant->next;
    }
  ptete = suppr_elem_list(ptete, &pcourant);
}
