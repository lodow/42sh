/*
** add_caractere_string.c for add_caractere_string.c in /home/remi/Projet/42sh/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 16:06:52 2013 remi
** Last update Thu Mar 21 18:04:32 2013 remi
*/

#include "my_func.h"

void		show_string(t_string *ptr, int pos)
{
  t_string	*pcourant;
  int		indice;

  if (ptr == NULL)
    return ;
  indice = 0;
  pcourant = ptr;
  my_putstr("[");
  while (pcourant != NULL)
    {
      if (indice >= pos)
	my_putchar(pcourant->caractere);
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  my_putstr("]");
}

void	add_caractere_string(t_string **ptr, char caractere, int pos)
{
  t_string	*pcourant;
  t_string	*elem;
  int		indice;

  if (*ptr == NULL)
    {
      if ((*ptr = malloc(sizeof(t_string))) == NULL)
	return ;
      (*ptr)->next = NULL;
      (*ptr)->back = NULL;
      (*ptr)->caractere = caractere;
      return ;
    }
  if ((elem = malloc(sizeof(t_string))) == NULL)
    return ;
  pcourant = *ptr;
  indice = 0;
  while (pcourant->next != NULL && indice != pos)
    {
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  if (pcourant->next == NULL)
    {
      elem->next = NULL;
      elem->back = pcourant;
      elem->caractere = caractere;
      pcourant->next = elem;
    }
  else
    {
      elem->next = pcourant->next;
      elem->back = pcourant;
      elem->caractere = caractere;
      pcourant->next->back = elem;
      pcourant->next = elem;
    }
}
