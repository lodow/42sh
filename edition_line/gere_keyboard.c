/*
** gere_keyboard.c for gere_keyboard in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 16:58:28 2013 remi robert
** Last update Tue Apr  2 09:02:08 2013 remi robert
*/

#include "my_func.h"

void	set_pos_left(t_param *param)
{
  param->current_pos.x -= 1;
  if (param->current_pos.x <= 0)
    {
      if (param->current_pos.y > param->begin_pos.y)
	{
	  param->current_pos.x = return_x();
	  param->current_pos.y -= 1;
	}
      else
	param->current_pos.x = 0;
    }
}

void	set_pos_right(t_param *param)
{
  param->current_pos.x += 1;
  if (get_len_string_with_pos(param) >= param->len_string)
    param->current_pos.x -= 1;
  if (param->current_pos.x >= return_x())
    {
      if (param->current_pos.y + 1 <= return_y())
	{
	  param->current_pos.x = 0;
	  param->current_pos.y += 1;
	}
      else
      	param->current_pos.x = return_x();
    }
}

void	gere_keyboard(t_param *param, char *buff)
{
  if (buff[0] == ESC && buff[2] == LEFT)
    set_pos_left(param);
  if (buff[0] == ESC && buff[2] == RIGHT)
    set_pos_right(param);
  curseur(param->current_pos.x, param->current_pos.y);
}
