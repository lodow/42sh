/*
** rempl_globb.c for rempl_globb in /home/remi/42sh/42sh/42sh/src/edition_line/globb
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Apr 30 13:14:02 2013 remi robert
** Last update Tue Apr 30 13:23:57 2013 remi robert
*/

#include "my_func.h"

int		rempl_globb(char *path, glob_t *globbuf)
{
  globbuf->gl_offs = 0;
  glob(path, GLOB_DOOFFS | GLOB_NOCHECK, NULL, globbuf);
  if (globbuf == NULL || globbuf->gl_pathv == NULL ||
      (globbuf->gl_pathc == 1 && str_cmp(globbuf->gl_pathv[0], path) == 1))
    return (0);
  return (1);
}

void	rempl_str_buff(char *buff, char *str)
{
  int	indice;

  indice = -1;
  while (str[++indice] != '\0')
    buff[indice] = str[indice];
  buff[indice] = '\0';
  if (str != NULL)
    free(str);
}
