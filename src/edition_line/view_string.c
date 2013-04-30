/*
** view_string.c for view_string in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 14:03:17 2013 remi robert
** Last update Tue Apr 30 11:39:21 2013 remi robert
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

int		return_nb_elem(t_string *ptete)
{
  t_string	*pcourant;
  int		indice;

  if (ptete == NULL)
    return (0);
  pcourant = ptete;
  indice = 0;
  while (pcourant != NULL)
    {
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  return (indice);
}

void	decale_window(t_param *param)
{
  int	indice;

  indice = ((param->len_string + param->begin_pos.x + 1) / return_x());
  if (((param->len_string + param->begin_pos.x) + 1) /
      return_x() > (return_y() - param->begin_pos.y) &&
      param->current_pos.y >= return_y())
    {
      while (indice + 1 > (return_y() - param->begin_pos.y) &&
	     param->current_pos.y >= return_y())
	{
	  curseur(param->begin_pos.x, param->begin_pos.y +
		  (return_y() - param->begin_pos.y), param->fd_tty);
	  delete_line_curser(param->fd_tty);
	  my_putstr("\n", 1, -1);
	  param->begin_pos.y -= 1;
	  param->prompt.y -= 1;
	  param->current_pos.y -= 1;
	  indice = indice - 1;
	}
    }
}

void		view_string(t_param *param)
{
  t_string	*pcourant;

  if (param == NULL || param->string == NULL)
    return ;
  decale_window(param);
  curseur(param->begin_pos.x, param->begin_pos.y, param->fd_tty);
  pcourant = param->string;
  while (pcourant != NULL)
    {
      my_putchar(pcourant->caractere);
      pcourant = pcourant->next;
    }
}
