/*
** init_globb.c for init_globb in /home/remi/42sh/42sh/42sh/src/edition_line/globb
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Apr 30 13:18:38 2013 remi robert
** Last update Tue Apr 30 13:30:22 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

void		init_struct_glob(t_glob *glob,
				 t_param *param)
{
  glob->fd_tty = param->fd_tty;
  glob->pos = 0;
  glob->x = 0;
  glob->y = 0;
  glob->len_max = 0;
  glob->nb_line = 0;
  glob->nb_colonne = 0;
}
