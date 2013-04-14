/*
** gere_direct_pos_cursor.c for gere_deire in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr 12 10:51:51 2013 remi robert
** Last update Fri Apr 12 11:05:10 2013 remi robert
*/

#include "../include/my_func.h"

void	begin_str(t_param *param)
{
  param->current_pos.x = param->begin_pos.x;
  param->current_pos.y = param->begin_pos.y;
}

void	end_str(t_param *param)
{
  int	indice;
  int	pos_x;
  int	pos_y;

  indice = 0;
  pos_y = param->begin_pos.y;
  pos_x = param->begin_pos.x;
  while (indice < param->len_string)
    {
      pos_x = pos_x + 1;
      if (pos_x == return_x())
	{
	  pos_x = 0;
	  pos_y = pos_y + 1;
	}
      indice = indice + 1;
    }
  param->current_pos.x = pos_x;
  param->current_pos.y = pos_y;
}
