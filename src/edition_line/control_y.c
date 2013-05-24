/*
** control_y.c for control_y in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May  9 12:22:50 2013 remi robert
** Last update Thu May 23 13:41:53 2013 remi robert
*/

#include "42sh.h"

void	gere_control_y(char *cmd, t_param *param)
{
  int	size_cmd;
  int	size_buff;
  int	indice;
  int	indice_buff;

  size_cmd = my_strlen(cmd);
  size_buff = my_strlen(param->buff_copy);
  if (size_buff == 0 || param->pos < 0 || param->pos > size_cmd)
    return ;
  indice = -1;
  while (++indice != size_buff)
    decal_string(cmd, param->pos + indice, ' ');
  indice = param->pos;
  indice_buff = 0;
  while (param->buff_copy[indice_buff] != '\0')
    {
      cmd[indice % SIZE_BUFFER] = param->buff_copy[indice_buff];
      indice += 1;
      indice_buff += 1;
    }
  if (param->pos == size_cmd)
    cmd[indice % SIZE_BUFFER] = '\0';
  view(cmd, param);
  begin_cmd(cmd, param);
  end_cmd(cmd, param);
}
