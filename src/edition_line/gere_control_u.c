/*
** gere_control_u.c for gere_control_u in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 16 09:19:19 2013 remi robert
** Last update Thu May 16 10:36:27 2013 remi robert
*/

#include "42sh.h"

void	gere_control_u(char *cmd, t_param *param)
{
  int	indice;
  char	buff[2];

  indice = param->pos + 1;
  buff[0] = DEL;
  buff[1] = '\0';
  while (--indice > 0)
    gere_delete(cmd, param, buff);
}
