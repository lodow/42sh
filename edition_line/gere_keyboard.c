/*
** gere_keyboard.c for gere_keyboard in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 16:58:28 2013 remi robert
** Last update Tue Apr  2 22:09:45 2013 remi robert
*/

#include "my_func.h"

void	set_pos_left(t_param **param)
{
  (*param)->current_pos.x -= 1;
  if ((*param)->current_pos.x <= 0)
    {
      if ((*param)->current_pos.y > (*param)->begin_pos.y)
	{
	  (*param)->current_pos.x = return_x();
	  (*param)->current_pos.y -= 1;
	}
      else
	(*param)->current_pos.x = 0;
    }
}

void	set_pos_right(t_param **param)
{
  (*param)->current_pos.x += 1;
  if (get_len_string_with_pos(*param) >= (*param)->len_string)
    (*param)->current_pos.x -= 1;
  if ((*param)->current_pos.x >= return_x())
    {
      if ((*param)->current_pos.y + 1 <= return_y())
	{
	  (*param)->current_pos.x = 0;
	  (*param)->current_pos.y += 1;
	}
      else
      	(*param)->current_pos.x = return_x();
    }
}

void		gere_delete(t_param **param)
{
  int		indice;
  t_string	*pcourant;
  t_string	*del_elem;

  if (*param == NULL || (*param)->string == NULL ||
      ((indice = get_len_string_with_pos(*param)) == (*param)->len_string ||
       (pcourant = get_pos_string((*param)->string, indice)) == NULL) ||
      pcourant->next == NULL)
    return ;
  del_elem = pcourant->next;
  if (pcourant->next->next != NULL)
    {
      pcourant->next = pcourant->next->next;
      pcourant->next->back = pcourant;
    }
  else
    pcourant->next = NULL;
  free(del_elem);
}

int		alone_caractere_in_string(t_string *pcourant, t_param **param)
{
  t_string	*index;
  int		indice;

  if ((*param)->string == NULL)
    return (FALSE);
  index = (*param)->string;
  indice = 0;
  while (index->next != NULL)
    {
      indice = indice + 1;
      index = index + 1;
    }
  if (indice == 0)
    {
      (*param)->string = NULL;
      free(pcourant);
      return (FALSE);
    }
  return (OK);
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
  free(del_elem);
}

void	gere_keyboard(t_param **param, char *buff)
{
  if (buff[0] == ESC && buff[2] == LEFT)
    set_pos_left(param);
  if (buff[0] == ESC && buff[2] == RIGHT)
    set_pos_right(param);
  if (buff[0] == DEL)
    gere_suppr(param);
  if (buff[0] == ESC && buff[1] == CRO && buff[2] == SUPPR)
    gere_delete(param);
  curseur((*param)->current_pos.x, (*param)->current_pos.y);
}
