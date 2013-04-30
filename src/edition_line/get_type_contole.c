/*
** get_type_contole.c for get_type_control in /home/remi/42sh/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Apr 30 13:08:39 2013 remi robert
** Last update Tue Apr 30 13:11:26 2013 remi robert
*/

#include "my_func.h"

int	gere_control_plus(char *buff, t_param **param)
{
  if (buff[0] == CTRLA)
    {
      begin_str(*param);
      return (OK);
    }
  if (buff[0] == CTRLE)
    {
      end_str(*param);
      return (OK);
    }
  return (FALSE);
}

int	gere_control(char *buff, t_param **param)
{
  if (buff[0] == CTRLK)
    {
      gere_control_k(param);
      return (OK);
    }
  if (buff[0] == CTRLY)
    {
      gere_control_y(param);
      return (OK);
    }
  if (buff[0] == CTRLU)
    {
      gere_control_u(param);
      return (OK);
    }
  if (buff[0] == CTRLL)
    {
      control_clear(param);
      return (OK);
    }
  return (gere_control_plus(buff, param));
}
