/*
** globb.c for globb in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 10 18:29:05 2013 remi robert
** Last update Mon May 20 15:19:16 2013 remi robert
*/

#include "42sh.h"

int	init_globb(char *path, glob_t *globb)
{
  int	indice;

  globb->gl_offs = 0;
  if (glob(path, GLOB_DOOFFS, NULL, globb) != 0 ||
      globb == NULL || globb->gl_pathv == NULL)
    return (0);
  indice = -1;
  if (my_strlen(globb->gl_pathv[0]) + 1 != my_strlen(path))
    return (1);
  while (globb->gl_pathv[0][++indice] != '\0' &&
	 path[indice] != '\0' && path[indice] != '*')
    if (globb->gl_pathv[0][indice] != path[indice])
      return (1);
  return (0);
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
  my_putstr(param->str_prompt, 1, -1);
  view(cmd, param);
  free(s);
}
