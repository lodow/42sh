/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu Dec 13 13:14:01 2012 Hugues
*/

#include <stdlib.h>
#include "dliste.h"

void		my_add_to_list(t_dlist **begin, void *data)
{
  t_dlist	*tmp;

  if (*begin == NULL)
    {
      if ((*begin = malloc(1 * sizeof(t_dlist))) == NULL)
        return ;
      (*begin)->data = data;
      (*begin)->next = NULL;
      (*begin)->prec = NULL;
      return ;
    }
  tmp = *begin;
  while ((tmp)->next != NULL)
    tmp = (tmp)->next;
  (tmp)->next = malloc(1 * sizeof(t_dlist));
  if ((tmp)->next != NULL)
    {
      (tmp)->next->data = data;
      (tmp)->next->next = NULL;
      (tmp)->next->prec = tmp;
    }
}
