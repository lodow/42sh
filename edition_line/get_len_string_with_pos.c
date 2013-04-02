/*
** get_len_string_with_pos.c for get_size in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 14:09:06 2013 remi robert
** Last update Tue Apr  2 22:10:13 2013 remi robert
*/

#include "my_func.h"

int	get_len_string_with_pos(t_param *param)
{
  if (param == NULL)
    return (FALSE);
  return (((param->current_pos.y - param->begin_pos.y) * return_x()) +
	  (param->current_pos.x - 1));
}
