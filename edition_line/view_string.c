/*
** view_string.c for view_string in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 14:03:17 2013 remi robert
** Last update Tue Apr  2 08:44:43 2013 remi robert
*/

#include "my_func.h"

t_string	*get_pos_string(t_string *ptete, int pos)
{
  int		indice;
  t_string	*pcourant;

  indice = 0;
  pcourant = ptete;
  while (pcourant != NULL)
    {
      if (indice == pos)
	return (pcourant);
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  return (pcourant);
}

void		view_string(t_param *param)
{
  int		indice;
  t_string	*pcourant;

  if (param == NULL || param->string == NULL)
    return ;
  indice = get_len_string_with_pos(param);
  if ((pcourant = get_pos_string(param->string, indice)) == NULL)
    return ;
  while (pcourant != NULL)
    {
      my_putchar(pcourant->caractere);
      pcourant = pcourant->next;
    }
}
