/*
** view_string.c for view_string in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 14:03:17 2013 remi robert
** Last update Tue Apr  2 21:41:12 2013 remi robert
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

int	return_nb_elem(t_string *ptete)
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

void	rez_print(t_param *param)
{
  int	indice_x;
  int	indice_y;

  indice_y = param->begin_pos.y - 1;
  indice_x = param->begin_pos.x;
  while (indice_y <= return_y())
    {
      curseur(indice_x, indice_y);
      while (indice_x != return_x())
	{
	  my_putchar(' ');
	  indice_x += 1;
	}
      indice_x = 0;
      indice_y += 1;
    }
}

void		view_string(t_param *param)
{
  t_string	*pcourant;
  int		indice;

  if (param == NULL || param->string == NULL)
    return ;
  indice = 0;
  curseur(param->begin_pos.x, param->begin_pos.y);
  pcourant = param->string;
  while (pcourant != NULL)
    {
      if (indice == return_x() - 1)
      	{
      	  my_putchar('\n');
      	  indice = 0;
      	}
      my_putchar(pcourant->caractere);
      pcourant = pcourant->next;
      indice = indice + 1;
    }
}

/* void		view_string(t_param *param) */
/* { */
/*   int		indice; */
/*   t_string	*pcourant; */

/*   if (param == NULL || param->string == NULL) */
/*     return ; */
/*   curseur(param->current_pos.x, param->current_pos.y); */
/*   indice = get_len_string_with_pos(param); */
/*   if ((pcourant = get_pos_string(param->string, indice)) == NULL) */
/*     return ; */
/*   while (pcourant != NULL) */
/*     { */
/*       my_putchar(pcourant->caractere); */
/*       pcourant = pcourant->next; */
/*     } */
/*  } */
