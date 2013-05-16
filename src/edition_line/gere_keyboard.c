/*
** gere_keyboard.c for gere_èkeyboard in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 16:20:31 2013 remi robert
** Last update Thu May 16 10:52:35 2013 remi robert
*/

#include "42sh.h"

void	gere_posright(char *cmd, t_param *param)
{
  if (param->pos + 1 <= my_strlen(cmd))
    {
      if (param->x + 1 >= return_x())
	{
	  apply_termcap(param->termcap.str_do, 0, param->fd_tty);
	  param->x = 0;
	  param->y += 1;
	}
      else
	{
	  apply_termcap(param->termcap.str_ri, 0, param->fd_tty);
	  param->x += 1;
	}
      param->pos += 1;
    }
}

void	gere_posleft(char *cmd, t_param *param)
{
  if (param->pos - 1 >= 0)
    {
      if (param->x <= 0)
	{
	  apply_termcap(param->termcap.str_up, 0, param->fd_tty);
	  apply_termcap(param->termcap.str_RI, return_x(), param->fd_tty);
	  param->x = return_x() - 1;
	  param->y -= 1;
	}
      else
	{
	  apply_termcap(param->termcap.str_le, 0, param->fd_tty);
	  param->x -= 1;
	}
      param->pos -= 1;
    }
}

int	gere_keyboard(char *buff, char *cmd, t_param *param)
{
  if (str_cmp(buff, STR_RIGHT) == 1)
    {
      gere_posright(cmd, param);
      return (0);
    }
  if (str_cmp(buff, STR_LEFT) == 1)
    {
      gere_posleft(cmd, param);
      return (0);
    }
  if ((buff[0] == DEL && buff[1] == END) ||
      (buff[0] == ESC && buff[1] == CRO && buff[2] == SUPPR))
    {
      gere_delete(cmd, param, buff);
      return (0);
    }
  return (gere_control(cmd, param, buff));
}
