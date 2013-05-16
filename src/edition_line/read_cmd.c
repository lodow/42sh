/*
** read_cmd.c for read_cmd in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 16:03:47 2013 remi robert
** Last update Thu May 16 11:23:38 2013 remi robert
*/

#include "42sh.h"

void	insert_caractere(char *cmd, t_param *param, char caratere)
{
  decal_string(cmd, param->pos, caratere);
  param->pos += 1;
}

void	add_caractere(char *cmd, t_param *param, char caratere)
{
  int	size;

  size = my_strlen(cmd);
  if (caratere >= 32 && caratere <= 126)
    {
      if (param->pos == size)
	{
	  cmd[param->pos % SIZE_BUFFER] = caratere;
	  cmd[(param->pos + 1) % SIZE_BUFFER] = '\0';
	  param->pos += 1;
	  return ;
	}
      else
	insert_caractere(cmd, param, caratere);
    }
}

char	*init_read_cmd(char *cmd, t_param *param)
{
  if (mod_raw(param->fd_tty) == EXIT_FAILURE)
    {
      my_putstr("Error mod_raw termcap\n", 2, -1);
      return (NULL);
    }
  if (SIZE_BUFFER <= 0 ||
      (cmd = malloc(sizeof(char) * SIZE_BUFFER)) == NULL)
    return (NULL);
  cmd[0] = '\0';
  get_pos_curser(&param->x, &param->y, param->fd_tty);
  param->begin_pos_x = param->x;
  param->begin_pos_y = param->y;
  param->pos = 0;
  return (cmd);
}

char	*read_cmd(t_param *param)
{
  int	ret;
  char	buff[10];

  my_putstr(param->str_prompt, 1, -1);
  param->cmd = NULL;
  param->cmd = init_read_cmd(param->cmd, param);
  ret = 1;
  while (ret > 0)
    {
      signal(SIGWINCH, gere_change_window);
      if ((ret = read(0, buff, 9)) == -1)
	return (NULL);
      buff[ret] = '\0';
      if (buff[0] == CTRLD && buff[1] == '\0')
	return (NULL);
      if (buff[0] == '\n' && buff[1] == '\0')
	return (return_string(param->cmd, param));
      if (get_window_size(param->cmd, param->begin_pos_x) == 1 &&
	  gere_keyboard(buff, param->cmd, param) == 1)
	{
	  add_caractere(param->cmd, param, buff[0]);
	  view(param->cmd, param);
	}
    }
  return (param->cmd);
}
