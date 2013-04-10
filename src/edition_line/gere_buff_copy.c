/*
** gere_buff_copy.c for gere_buff_copy in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  8 17:49:14 2013 remi robert
** Last update Tue Apr  9 17:05:33 2013 remi robert
*/

#include "../../include/my_func.h"

void	set_buff_copy(t_param **param, t_string *pcourant)
{
  int	indice;

  if (*param == NULL || pcourant == NULL)
    return ;
  indice = 0;
  while (indice < 2046 && pcourant != NULL)
    {
      (*param)->buff_copy[indice] = pcourant->caractere;
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  (*param)->buff_copy[indice] = END;
}

void		get_buff_copy(t_param **param)
{
  int		save_x;
  int		save_y;
  int		indice;

  save_y = (*param)->current_pos.y;
  save_x = (*param)->current_pos.x;
  indice = 0;
  while (indice < 2048 && (*param)->buff_copy[indice] != END)
    {
      add_caratere_list_with_buff(param, (*param)->buff_copy[indice]);
      if ((*param)->current_pos.x >= return_x())
	{
	  (*param)->current_pos.x = 0;
	  (*param)->current_pos.y += 1;
	}
      indice = indice + 1;
    }
  (*param)->current_pos.x = save_x;
  (*param)->current_pos.y = save_y;
}
