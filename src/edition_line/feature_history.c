/*
** feature_history.c for feature_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr 12 13:30:27 2013 remi robert
** Last update Sun Apr 14 16:09:19 2013 remi robert
*/

#include "my_func.h"

char		*return_pos_history(t_history *ptete, int pos)
{
  int		indice;
  t_history	*pcourant;

  if (ptete == NULL)
    return (NULL);
  indice = 0;
  pcourant = ptete;
  while (pcourant != NULL && indice != pos)
    {
      if (indice + 1 == pos)
	return (pcourant->cmd);
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  return (NULL);
}

void		add_elem_new_cmd(t_string **ptete, char caractere)
{
  t_string	*new_elem;
  t_string	*pcourant;

  if (*ptete == NULL)
    {
      if ((*ptete = malloc(sizeof(t_string))) == NULL)
	return ;
      (*ptete)->caractere = caractere;
      (*ptete)->next = NULL;
      (*ptete)->back = NULL;
      return ;
    }
  if ((new_elem = malloc(sizeof(t_string))) == NULL)
    return ;
  pcourant = *ptete;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  pcourant->next = new_elem;
  new_elem->caractere = caractere;
  new_elem->back = pcourant;
  new_elem->next = NULL;
}

void	recup_new_string(t_param **param, char *cmd)
{
  int	indice;

  indice = 0;
  if (cmd == NULL)
    return ;
  while (cmd[indice] != '\0')
    {
      add_elem_new_cmd(&((*param)->string), cmd[indice]);
      indice = indice + 1;
    }
  (*param)->len_string = indice;
  end_str(*param);
}
