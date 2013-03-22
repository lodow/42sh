/*
** suppr_caractere_string.c for suppr_caractere_string in /home/remi/Projet/42sh/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Fri Mar 22 13:03:17 2013 remi
** Last update Fri Mar 22 13:23:21 2013 remi
*/

#include "my_func.h"

void		suppr_caractere_string(t_param **param)
{
  t_string	*pcourant;
  int		indice;

  if ((*param)->ptr == NULL)
    return ;
  indice = 0;
  pcourant = (*param)->ptr;
  while (pcourant != NULL)
    {
      if (indice >= (*param)->current_pos)
	my_putchar(' ');
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  pcourant = (*param)->ptr;
  indice = 0;
  while (pcourant != NULL && (*param)->current_pos != indice)
    {
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  free_string(pcourant->next);
  pcourant->next = NULL;
}
