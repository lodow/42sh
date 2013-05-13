/*
** control_y_k.c for control_k_y in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May  9 12:19:59 2013 remi robert
** Last update Thu May  9 12:23:08 2013 remi robert
*/

#include "termcap.h"

void	gere_control_k(char *cmd, t_param *param)
{
  int	size;
  int	indice;
  int	indice_buff;

  size = my_strlen(cmd);
  if (size == 0 || param->pos < 0 || param->pos >= size)
    return ;
  indice = param->pos;
  indice_buff = 0;
  while (cmd[indice] != '\0')
    {
      param->buff_copy[indice_buff] = cmd[indice];
      indice += 1;
      indice_buff += 1;
    }
  cmd[param->pos] = '\0';
  param->buff_copy[indice_buff] = '\0';
  refresh_view(cmd, param);
  view(cmd, param);
}
