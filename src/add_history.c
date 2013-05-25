/*
** add_history.c for add_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr 12 12:53:40 2013 remi robert
** Last update Sat May 25 23:52:58 2013 remi robert
*/

#include "my_func.h"

void	rempl_new_history(t_history **elem, char *str)
{
  int	indice;

  if (*elem == NULL || str == NULL || str[0] == '\0' ||
      ((*elem)->cmd = malloc(my_strlen(str) + 1)) == NULL)
    return ;
  indice = 0;
  while (str[indice] != '\0')
    {
      (*elem)->cmd[indice] = str[indice];
      indice = indice + 1;
    }
  (*elem)->cmd[indice] = '\0';
}

void		add_history(t_history **phead, char *cmd)
{
  t_history	*new_history;
  static int	nb_history = 0;

  if (*phead == NULL)
    {
      if ((*phead = malloc(sizeof(t_history))) == NULL)
	return ;
      rempl_new_history(phead, cmd);
      (*phead)->nb_history = nb_history;
      nb_history = nb_history + 1;
      (*phead)->back = NULL;
      (*phead)->next = NULL;
      return ;
    }
  if (cmd == NULL || str_cmp(cmd, (*phead)->cmd) == 1 ||
      (new_history = malloc(sizeof(t_history))) == NULL)
    return ;
  (*phead)->back = new_history;
  new_history->back = NULL;
  new_history->next = *phead;
  new_history->nb_history = nb_history;
  nb_history = nb_history + 1;
  rempl_new_history(&new_history, cmd);
  *phead = new_history;
}
