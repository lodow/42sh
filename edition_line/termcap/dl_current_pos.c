/*
** dl_current_pos.c for dl_current_pos.c in /home/remi/Projet/edition_line/termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  8 16:36:04 2013 remi robert
** Last update Tue Apr  9 17:03:14 2013 remi robert
*/

#include "../../include/my_func.h"

void	dl_current_pos(t_param *param)
{
  char	*s;

  curseur(param->current_pos.x, param->current_pos.y);
  s = tgetstr("dl", NULL);
  my_put_str(s);
}
