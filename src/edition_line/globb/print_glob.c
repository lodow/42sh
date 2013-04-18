/*
** print_glob.c for print_glob in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Apr 18 08:50:49 2013 remi robert
** Last update Thu Apr 18 15:41:58 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

int	get_size_glob(glob_t *globbuf)
{
  int	size;
  int	indice;
  int	len;

  indice = 0;
  size = 0;
  while (indice < (int)globbuf->gl_pathc)
    {
      len = my_strlen(globbuf->gl_pathv[indice]);
      if (len > size)
	size = len;
      indice = indice + 1;
    }
  return (size + 2);
}

void	view_glob(t_glob *param_glob, int selector)
{
  int	indice;

  indice = 0;
  while (indice < (int)param_glob->glob.gl_pathc)
    {
      curseur(param_glob->x, param_glob->y);
      param_glob->x += param_glob->len_max;
      if (selector == indice)
	{
	  my_put_str(VERT);
	  my_put_str(INVERSE);
	}
      my_put_str(param_glob->glob.gl_pathv[indice]);
      if (selector == indice)
	my_put_str(REZ);
      if (param_glob->x >= return_x() ||
	  param_glob->x + param_glob->len_max > return_x())
	{
	  my_put_str("\n");
	  param_glob->x = 0;
	  param_glob->y += 1;
	}

      indice = indice + 1;
    }
}

void	calc_colonne_glob(t_glob *param_glob)
{
  int	indice;
  int	x;

  indice = 0;
  x = 0;
  param_glob->nb_colonne = 0;
  while (indice < (int)param_glob->glob.gl_pathc)
    {
      x += param_glob->len_max;
      if (x >= return_x() ||
	  x + param_glob->len_max > return_x())
	{
	  x = 0;
	  param_glob->nb_colonne += 2;
	}
      indice = indice + 1;
    }
}

void	print_glob(t_param **param, t_glob *param_glob, int selector)
{
  param_glob->len_max = get_size_glob(&(param_glob->glob));
  param_glob->nb_line = (return_x() / param_glob->len_max) + 1;
  calc_colonne_glob(param_glob);
  my_putstr("\n", 1, -1);
  get_pos_curser(&(param_glob->x), &(param_glob->y));
  param_glob->x = 0;
  view_glob(param_glob, selector);
  my_put_str("\n");
}
