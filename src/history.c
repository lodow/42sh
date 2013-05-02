/*
** free_history.c for free_history in /home/remi/42sh/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May  2 11:04:16 2013 remi robert
** Last update Thu May  2 11:18:34 2013 remi robert
*/

#include "my_func.h"
#include "42sh.sh"

void	free_history(t_history *ptete)
{
  t_history	*pcourant;

  if (ptete == NULL)
    return ;
  pcourant = ptete;
  while (pcourant != NULL)
    {
      pcourant = pcourant->next;
      if (pcourant->back != NULL)
	{
	  if (pcourant->back->cmd != NULL)
	    free(pcourant->back->cmd);
	  free(pcourant->back);
	}
    }
}
