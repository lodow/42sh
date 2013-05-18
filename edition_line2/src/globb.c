/*
** globb.c for globb in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 10 18:29:05 2013 remi robert
** Last update Sat May 11 14:51:05 2013 remi robert
*/

#include "termcap.h"

int	init_globb(char *path, glob_t *globb)
{
  globb->gl_offs = 0;
  if (glob(path, GLOB_DOOFFS, NULL, globb) != 0 ||
      globb == NULL || globb->gl_pathv == NULL)
    return (0);
  return (1);
}

void		globb(char *cmd, t_param *param)
{
  glob_t	globb;
  char		*s;

  s = return_globb_str(cmd, param->pos);
  if (init_globb(s, &globb) == 0)
    return ;
  completation(cmd, &globb, param, s);
  curseur(param->x, param->y);
  view_globb(&globb, param);
  my_putstr(param->prompt);
  view(cmd, param);
  free(s);
}
