/*
** gere_keyboard.c for gere_keyboard in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 16:58:28 2013 remi robert
** Last update Mon Apr 15 08:38:37 2013 remi robert
*/

#include "my_func.h"

void	set_pos_left(t_param **param)
{
  (*param)->current_pos.x -= 1;
  if ((*param)->current_pos.y == (*param)->begin_pos.y &&
      (*param)->current_pos.x < (*param)->begin_pos.x)
    {
      (*param)->current_pos.x += 1;
      return ;
    }
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

int		alone_caractere_in_string(t_string *pcourant,
					  t_param **param)
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
      index = index->next;
    }
  if (indice == 0)
    {
      (*param)->string = NULL;
      free(pcourant);
      return (FALSE);
    }
  return (OK);
}

void	gere_keyboard(t_param **param, char *buff, t_history **history)
{
  if (buff[0] == 9 && buff[1] == '\0')
    gere_globb(param);
  if (str_cmp(buff, BEGIN_STR) == 1)
    begin_str(*param);
  if (str_cmp(buff, END_STR) == 1)
    end_str(*param);
  if (str_cmp(buff, STR_LEFT) == 1)
    set_pos_left(param);
  if (str_cmp(buff, STR_RIGHT) == 1)
    set_pos_right(param);
  if (str_cmp(buff, STR_UP) == 1 || str_cmp(buff, STR_DOWN) == 1)
    gere_history(param, buff, history);
  if (buff[0] == DEL && buff[1] == END)
    gere_suppr(param);
  if (buff[0] == ESC && buff[1] == CRO && buff[2] == SUPPR)
    gere_delete(param);
  curseur((*param)->current_pos.x, (*param)->current_pos.y);
}
