/*
** start_end_cmd.c for start_end_cmd in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon May  6 13:00:47 2013 remi robert
** Last update Tue May 14 19:59:58 2013 remi robert
*/

#include "42sh.h"

void	begin_cmd(char *cmd, t_param *param)
{
  param->x = param->begin_pos_x;
  param->y = param->begin_pos_y;
  param->pos = 0;
  curseur(param->x, param->y);
}

void	end_cmd(char *cmd, t_param *param)
{
  int	size_x;
  int	size_y;

  size_x = return_x();
  size_y = return_y();
  if (cmd[0] == '\0')
    {
      param->x = param->begin_pos_x;
      param->y = param->begin_pos_y;
      param->pos = 0;
      return ;
    }
  while (cmd[param->pos] != '\0')
    {
      param->pos += 1;
      param->x += 1;
      if (param->x == size_x)
	{
	  param->x = 0;
	  if (param->y < size_y)
	    param->y += 1;
	}
    }
  curseur(param->x, param->y);
}
