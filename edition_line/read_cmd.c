/*
** read_cmd.c for read_cmd in /home/remi/Projet/42sh/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 16:35:19 2013 remi
** Last update Thu Mar 21 18:25:57 2013 remi
*/

#include "my_func.h"

void	end_read(t_param *param)
{
  char	*s;

  my_putstr("\n");
  if ((s = return_string(param->ptr)) == NULL)
      return ;
  my_putstr(s);
  free(s);
  my_putstr("\n");
}

int	gere_keyboard(t_param *param, char *buff)
{
  if (buff[0] != ESC || buff[1] == '\0' && buff[0] != '\n')
    return (0);
  if (buff[2] == LEFT)
    {
      curseur(param->curser.begin_x - 1, param->curser.begin_y);
      param->current_pos = param->current_pos - 1;
    }
  return (1);
  //if (tab[2] == RIGHT)
}

void	init_read_cmd(t_param *param)
{
  param->len_string = 0;
  param->current_pos = 0;
  get_pos_curser(&(param->curser.begin_x),
		 &(param->curser.begin_y));
  curseur(0, param->curser.begin_y);
}

void	read_cmd(t_param *param)
{
  char	buff[5];
  int	temp;

  buff[1] = '\0';
  temp = 0;
  init_read_cmd(param);
  while (1)
    {
      buff[1] = '\0';
      read(0, buff, 5);
      if (gere_keyboard(param, buff) == 0 &&
	  buff[1] == '\0' && buff[0] != '\n')
	{
	  param->current_pos = param->current_pos + 1;
	  add_caractere_string(&(param->ptr), buff[0], param->current_pos);
	  param->len_string = param->len_string + 1;
	  show_string(param->ptr, param->current_pos);
	}
      if (buff[0] == '\n')
	{
	  end_read(param);
	  return ;
	}
    }
}
