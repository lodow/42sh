/*
** my_select.c for my_select in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Apr 18 14:08:00 2013 remi robert
** Last update Thu Apr 18 15:40:48 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

void	gere_keyboard_globb(char *buff, t_glob *param_glob, int max)
{
  if (str_cmp(buff, STR_UP) == 1)
    {
      param_glob->pos -= 1;
      if (param_glob->pos < 0)
	param_glob->pos = max - 1;
      return ;
    }
  if (str_cmp(buff, STR_DOWN) == 1)
    {
      param_glob->pos += 1;
      if (param_glob->pos >= max)
	param_glob->pos = 0;
      return ;
    }
}

char	*get_selected_globb(t_glob *param)
{
  int	indice;

  indice = 0;
  while (indice < (int)param->glob.gl_pathc)
    {
      if (indice == param->pos)
	return (param->glob.gl_pathv[indice]);
      indice = indice + 1;
    }
  return (NULL);
}

void	my_select_glob(t_param **param,
		       char *str_globb,
		       t_glob *param_glob)
{
  char	buff[10];
  int	ret;
  int	y;

  ret = 1;
  print_glob(param, param_glob, param_glob->pos);
  y = param_glob->y - (param_glob->nb_colonne + 1);
  while (ret > 0)
    {
      my_memset(buff, 10);
      if ((ret = read(0, buff, 10)) == -1 ||
	  (buff[0] == ESC && buff[1] == '\0'))
	return ;
      if (buff[0] == '\n' && buff[1] == '\0')
      	{
      	  completation_cmd(str_globb, get_selected_globb(param_glob), param);
      	  return ;
      	}
      gere_keyboard_globb(buff, param_glob, param_glob->glob.gl_pathc);
      param_glob->y = y;
      param_glob->x = 0;
      view_glob(param_glob, param_glob->pos);
      my_putstr("\n", 1, -1);
    }
}
