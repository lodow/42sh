/*
** print_prompt.c for print_prompt in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 10 08:55:38 2013 remi robert
** Last update Thu May  2 22:45:52 2013 remi robert
*/

#include "my_func.h"

void	print_prompt(t_param *param)
{
  if (param->str_prompt != NULL)
    {
      invisible_curseur(param->fd_tty);
      curseur(param->prompt.x, param->prompt.y, param->fd_tty);
      my_putstr(param->str_prompt, 1, -1);
      curseur(param->current_pos.x, param->current_pos.y, param->fd_tty);
      view_curser(param->fd_tty);
    }
}
