/*
** dl_current_pos.c for dl_current_pos.c in /home/remi/Projet/edition_line/termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  8 16:36:04 2013 remi robert
** Last update Sun Apr 14 16:10:40 2013 remi robert
*/

#include "my_func.h"

void	delete_line_curser(void)
{
  char	*s;

  s = tgetstr("dl", NULL);
  my_put_str(s);
}

void	dl_current_pos(t_param *param)
{
  int	indice;
  int	size;
  int	x;

  size = (param->len_string + my_strlen(param->buff_copy)) / return_x();
  indice = 0;
  x = param->begin_pos.x;
  while (indice != size + 1)
    {
      curseur(x, param->begin_pos.y + indice);
      delete_line_curser();
      x = 0;
      indice = indice + 1;
    }
  curseur(param->current_pos.x, param->current_pos.y);
  delete_line_curser();
  curseur(param->begin_pos.x, param->begin_pos.y);
  delete_line_curser();
}
