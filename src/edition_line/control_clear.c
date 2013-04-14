/*
** control_clear.c for control_clear in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 10 09:10:33 2013 remi robert
** Last update Sun Apr 14 16:08:57 2013 remi robert
*/

#include "my_func.h"

void	control_clear(t_param **param)
{
  curseur(0, 0);
  clear_screem();
  my_put_str((*param)->str_prompt);
  (*param)->current_pos.x = (*param)->current_pos.x - (*param)->begin_pos.x;
  (*param)->current_pos.y = (*param)->current_pos.y - (*param)->begin_pos.y;
  get_pos_curser(&((*param)->begin_pos.x), &((*param)->begin_pos.y));
  (*param)->prompt.x = 0;
  (*param)->prompt.y = (*param)->begin_pos.y;
  curseur((*param)->current_pos.x, (*param)->current_pos.y);
}
