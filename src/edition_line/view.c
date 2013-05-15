/*
** view.c for view in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 17:28:49 2013 remi robert
** Last update Wed May 15 14:14:38 2013 remi robert
*/

#include "42sh.h"

void	calc_other_decallage(char *cmd, t_param *param)
{
  int	size;
  int	size_y;
  int	current_size;
  int	indice;

  size = my_strlen(cmd) + param->begin_pos_x;
  size_y = (size / return_x()) + 1;
  current_size = (return_y() - param->begin_pos_y) + 1;
  if ((size_y - current_size) <= 0 ||
      current_size > size_y || size_y == return_x())
    return ;
  indice = 0;
  curseur(param->begin_pos_x, param->begin_pos_y);
  param->begin_pos_y -= (size_y - current_size);
  while (indice != return_y() - param->begin_pos_y)
    {
      indice += 1;
      my_putstr("\n", 1, 1);
    }
}

void	view(char *cmd, t_param *param)
{
  refresh_view(cmd, param);
  if (cmd != NULL)
    calc_other_decallage(cmd, param);
  curseur(param->begin_pos_x, param->begin_pos_y);
  if (cmd != NULL)
    update_pos_y(cmd, param, param->begin_pos_x, param->begin_pos_y);
  curseur(param->begin_pos_x, param->begin_pos_y);
  my_putstr_view(cmd, param->begin_pos_x, param);
}
