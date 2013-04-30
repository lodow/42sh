/*
** init_struct_param.c for para in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Apr  9 15:26:37 2013 remi robert
** Last update Tue Apr 30 11:35:39 2013 remi robert
*/

#include "my_func.h"

void		init_struct_param(t_param *param)
{
  mod_raw(param->fd_tty);
  get_pos_curser(&(param->begin_pos.x), &(param->begin_pos.y),
		 param->fd_tty);
  param->pos_history = 0;
  param->current_pos.x = param->begin_pos.x;
  param->current_pos.y = param->begin_pos.y;
  param->prompt.y = param->begin_pos.y;
  param->prompt.x = 0;
  curseur(param->current_pos.x, param->current_pos.y, param->fd_tty);
  param->string = NULL;
  param->len_string = 0;
  param->buff_copy[0] = END;
}
