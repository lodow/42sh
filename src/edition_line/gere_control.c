/*
** gere_control.c for gere_controle in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr  5 15:49:00 2013 remi robert
** Last update Sat Apr 13 10:55:14 2013 remi robert
*/

#include "my_func.h"

int	get_number_caractere_del(t_string *pcourant)
{
  int	indice;

  indice = 0;
  if (pcourant == NULL)
    return (indice);
  while (pcourant != NULL)
    {
      indice += 1;
      pcourant = pcourant->next;
    }
  return (indice - 1);
}

void	delete_all_list(t_param **param)
{
  free_string((*param)->string);
  (*param)->string = NULL;
}

void		gere_control_u(t_param **param)
{
  t_string	*pcourant;
  t_string	*pcourant_string;
  int		indice;

  if (*param == NULL || (*param)->string == NULL)
    return ;
  indice = get_len_string_with_pos(*param) + 1;
  if (indice >= (*param)->len_string)
    {
      delete_all_list(param);
      return ;
    }
  if ((pcourant = get_pos_string((*param)->string, indice)) == NULL)
    return ;
  pcourant_string = (*param)->string;
  indice = 0;
  while (pcourant_string != NULL && pcourant_string != pcourant)
    {
      pcourant_string = pcourant_string->next;
      free(pcourant_string->back);
      indice = indice + 1;
    }
  gere_end_control_u(param, pcourant, indice);
}

void		gere_control_k(t_param **param)
{
  t_string	*pcourant;

  if (*param == NULL || (*param)->string == NULL)
    return ;
  my_memset((*param)->buff_copy, 2048);
  if ((pcourant = get_pos_string((*param)->string,
				 get_len_string_with_pos(*param))) == NULL)
    {
      set_buff_copy(param, (*param)->string);
      free_string((*param)->string);
      (*param)->len_string = 0;
      (*param)->string = NULL;
      return ;
    }
  set_buff_copy(param, pcourant->next);
  (*param)->len_string = (*param)->len_string -
    get_number_caractere_del(pcourant);
  free_string(pcourant->next);
  end_str(*param);
  pcourant->next = NULL;
}

void		gere_control_y(t_param **param)
{
  if (*param == NULL || (*param)->buff_copy[0] == END)
    return ;
  get_buff_copy(param);
}
