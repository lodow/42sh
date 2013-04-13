/*
** suppression.c for suppression in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr  3 08:07:53 2013 remi robert
** Last update Sat Apr 13 10:54:20 2013 remi robert
*/

#include "my_func.h"

int		gere_first_elem(t_param **param)
{
  t_string	*del_elem;

  if (get_len_string_with_pos(*param) != -1)
    return (0);
  (*param)->len_string -= 1;
  if ((*param)->string->next == NULL)
    {
      free ((*param)->string);
      (*param)->string = NULL;
      return (1);
    }
  del_elem = (*param)->string;
  (*param)->string = (*param)->string->next;
  (*param)->string->back = NULL;
  free(del_elem);
  return (1);
}

void		gere_delete(t_param **param)
{
  int		indice;
  t_string	*pcourant;
  t_string	*del_elem;

  if (*param == NULL || (*param)->string == NULL ||
      gere_first_elem(param) == 1 ||
      ((indice = get_len_string_with_pos(*param)) == (*param)->len_string ||
       (pcourant = get_pos_string((*param)->string, indice)) == NULL) ||
      pcourant->next == NULL)
    return ;
  del_elem = pcourant->next;
  (*param)->len_string -= 1;
  if (pcourant->next->next != NULL)
    {
      pcourant->next = pcourant->next->next;
      pcourant->next->back = pcourant;
    }
  else
    pcourant->next = NULL;
  free(del_elem);
}

void		gere_suppr(t_param **param)
{
  int		indice;
  t_string	*pcourant;
  t_string	*del_elem;

  indice = get_len_string_with_pos(*param);
  if ((*param) == NULL || (*param)->string == NULL ||
      (pcourant = get_pos_string((*param)->string, indice)) == NULL ||
      alone_caractere_in_string(pcourant, param) == FALSE)
    return ;
  del_elem = pcourant;
  (*param)->len_string -= 1;
  if (pcourant->next != NULL && pcourant->back != NULL)
    {
      pcourant->back->next = pcourant->next;
      pcourant->next->back = pcourant->back;
    }
  if (pcourant->next == NULL)
    pcourant->back->next = NULL;
  if (pcourant->back == NULL)
    {
      pcourant->next->back = NULL;
      (*param)->string = pcourant->next;
    }
  set_pos_left(param);
  free(del_elem);
}
