/*
** rm_first_lm_list.c for rm_fist_elem_lis in /home/remi/Projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar  7 08:50:33 2013 remi
** Last update Thu Mar  7 08:58:28 2013 remi
*/

#include "my_func.h"

int		number_elem_history(t_list **ptete)
{
  t_list	*pcourant;
  int		indice;

  if (*ptete == NULL)
    return (0);
  indice = 0;
  pcourant = *ptete;
  while (pcourant != NULL)
    {
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  return (indice);
}

void		rm_first_lm_list(t_list **ptete)
{
  t_list	*pcourant;

  if ((*ptete == NULL) || number_elem_history(ptete) < 21)
    return ;
  pcourant = *ptete;
  *ptete = (*ptete)->next;
  free(pcourant->tab);
  free(pcourant);
}
