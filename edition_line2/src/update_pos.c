/*
** update_pos.c for update in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May  9 12:24:10 2013 remi robert
** Last update Mon May 13 12:07:16 2013 remi robert
*/

#include "termcap.h"

void	update_pos_y(char *cmd, t_param *param, int pos_x, int pos_y)
{
  int	indice;
  int	size_x;

  size_x = return_x();
  indice = 0;
  while (cmd[indice] != '\0' && indice <= param->pos)
    {
      while (cmd[indice] != '\0' &&
	     pos_x < size_x && indice <= param->pos)
	{
	  indice += 1;
	  pos_x += 1;
	}
      if (pos_x > size_x - 1)
	{
	  pos_y += 1;
	  pos_x = 0;
	}
    }
  if (cmd[indice] != '\0')
    pos_x -= 1 ;
  param->y = pos_y;
  param->x = pos_x;
}
