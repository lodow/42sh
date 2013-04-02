/*
** read_cmd.c for read_cmd in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 12:32:15 2013 remi robert
** Last update Tue Apr  2 11:46:32 2013 remi robert
*/

#include "my_func.h"

void	gere_buff(char *buff, t_param *param)
{
  if (buff[1] == '\0' && buff[0] != ESC)
    {
      param->len_string += 1;
      param->current_pos.x += 1;
      if (param->current_pos.x >= return_x())
	{
	  if (param->current_pos.y >= return_y())
	    {
	      param->begin_pos.y -= 1;
	      param->current_pos.y -= 1;
	    }
	  param->current_pos.x = 0;
	  param->current_pos.y += 1;
	}
      add_caractere(&(param->string), buff[0], param);
      view_string(param);
      return ;
    }
  gere_keyboard(param, buff);
}

char	*read_cmd(t_param *param)
{
  char	buff[5];
  int	ret;

  ret = 1;
  while (ret > 0)
    {
      buff[1] = '\0';
      if ((ret = read(0, buff, 5)) == -1)
	return (NULL);
      if (buff[0] == '\n')
	return (return_string(param->string));
      gere_buff(buff, param);
      curseur(param->current_pos.x, param->current_pos.y);
    }
  return (NULL);
}
