/*
** read_cmd.c for read_cmd in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 12:32:15 2013 remi robert
** Last update Thu May  2 09:41:22 2013 remi robert
*/

#include "my_func.h"

void	gere_buff(char *buff, t_param **param, t_history **history, char **env)
{
  if (buff[1] == '\0' && buff[0] != ESC && buff[0] != DEL && buff[0] != '\t')
    {
      (*param)->len_string += 1;
      (*param)->current_pos.x += 1;
      if ((*param)->current_pos.x >= return_x((*param)->fd_tty))
	{
	  if ((*param)->current_pos.y >= return_y((*param)->fd_tty))
	    {
	      (*param)->begin_pos.y -= 1;
	      (*param)->current_pos.y -= 1;
	    }
	  (*param)->current_pos.x = 0;
	  (*param)->current_pos.y += 1;
	}
      add_caractere(&((*param)->string), buff[0], *param);
      return ;
    }
  gere_keyboard(param, buff, history, env);
}

void	gere_null_list(t_param **param)
{
  if ((*param)->string == NULL)
    {
      dl_current_pos(*param);
      (*param)->current_pos.x = (*param)->begin_pos.x;
      (*param)->current_pos.y = (*param)->begin_pos.y;
      (*param)->len_string = 0;
      dl_current_pos(*param);
    }
}

char	*read_cmd(t_param *param, t_history **history, char **env)
{
  char	buff[10];
  int	ret;

  ret = 1;
  init_struct_param(param);
  while (ret > 0)
    {
      print_prompt(param);
      my_memset(buff, 10);
      if ((ret = read(0, buff, 10)) == -1)
      	return (NULL);
      if (buff[0] == CTRLD && buff[1] == '\0')
	return (NULL);
      if (buff[0] == '\n')
	return (return_saisi(param, history));
      if (gere_control(buff, &param) == FALSE)
	gere_buff(buff, &param, history, env);
      dl_current_pos(param);
      gere_null_list(&param);
      view_string(param);
      curseur(param->current_pos.x, param->current_pos.y, param->fd_tty);
    }
  return (return_string(param->string));
}
