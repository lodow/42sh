/*
** delete_history.c for deleteèhistory in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat Apr 13 08:46:11 2013 remi robert
** Last update Sun Apr 14 19:12:51 2013 Hugues
*/

#include "42sh.h"

t_history	*suppr_elem_list(t_history **ptete, t_history **pcourant)
{
  if ((*pcourant)->back == NULL && (*pcourant)->next == NULL)
    {
      free(*pcourant);
      return (NULL);
    }
  if ((*pcourant)->back == NULL)
    {
      *ptete = (*pcourant)->next;
      (*ptete)->back = NULL;
      return (*ptete);
    }
  if ((*pcourant)->next == NULL)
    {
      (*pcourant)->back->next = NULL;
      free(*pcourant);
      return (*ptete);
    }
  (*pcourant)->back->next = (*pcourant)->next;
  (*pcourant)->next->back = (*pcourant)->back;
  free(*pcourant);
  return (*ptete);
}

void		rm_history_d(t_history **ptete, int pos)
{
  t_history	*pcourant;

  if (*ptete == NULL)
    return ;
  pcourant = *ptete;
  while (pcourant != NULL)
    {
      if (pos == pcourant->nb_history && pcourant != NULL)
	{
	  *ptete = suppr_elem_list(ptete, &pcourant);
	  return ;
	}
      pcourant = pcourant->next;
    }
}
