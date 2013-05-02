/*
** init_struct_param.c for para in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Apr  9 15:26:37 2013 remi robert
** Last update Thu May  2 08:52:22 2013 remi robert
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
  param->prompt.x = param->begin_pos.x;
  param->begin_pos.x += my_strlen(param->str_prompt);
  param->current_pos.x += my_strlen(param->str_prompt);
  curseur(param->current_pos.x, param->current_pos.y, param->fd_tty);
  param->string = NULL;
  param->len_string = 0;
}
