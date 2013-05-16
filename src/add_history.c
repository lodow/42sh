/*
** add_history.c for add_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr 12 12:53:40 2013 remi robert
** Last update Thu May 16 14:29:19 2013 remi robert
*/

#include "my_func.h"

void   	rempl_new_history(t_history **elem, char *str)
{
  int  	indice;

  if (*elem == NULL || str == NULL ||
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

void		add_history(t_history **ptete, char *cmd)
{
  t_history	*new_history;
  static int	nb_history = 0;

  if (*ptete == NULL)
    {
      if ((*ptete = malloc(sizeof(t_history))) == NULL)
	return ;
      rempl_new_history(ptete, cmd);
      (*ptete)->nb_history = nb_history;
      nb_history = nb_history + 1;
      (*ptete)->back = NULL;
      (*ptete)->next = NULL;
      return ;
    }
  if ((new_history = malloc(sizeof(t_history))) == NULL)
    return ;
  (*ptete)->back = new_history;
  new_history->back = NULL;
  new_history->next = *ptete;
  new_history->nb_history = nb_history;
  nb_history = nb_history + 1;
  rempl_new_history(&new_history, cmd);
  *ptete = new_history;
}
