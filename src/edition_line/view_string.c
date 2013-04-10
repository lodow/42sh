/*
** view_string.c for view_string in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 14:03:17 2013 remi robert
** Last update Wed Apr 10 10:26:32 2013 remi robert
*/

#include "../../include/my_func.h"
#include "../../include/42sh.h"

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

void		view_string(t_param *param)
{
  t_string	*pcourant;
  int		indice;
  int		indice_y;

  if (param == NULL || param->string == NULL)
    return ;
  indice_y = param->begin_pos.y;
  curseur(param->begin_pos.x, param->begin_pos.y);
  pcourant = param->string;
  indice = param->begin_pos.x;
  while (pcourant != NULL)
    {
      indice = indice + 1;
      my_putstr(&(pcourant->caractere), 1, 1);
      if (indice >= return_x())
      	{
	  my_putstr(" ", 1, 1);
      	  indice = 0;
	  indice_y += 1;
	  curseur(0, indice_y);
      	}
      pcourant = pcourant->next;
    }
}
