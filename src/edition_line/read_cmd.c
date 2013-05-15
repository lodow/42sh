/*
** read_cmd.c for read_cmd in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 16:03:47 2013 remi robert
** Last update Wed May 15 10:49:25 2013 remi robert
*/

#include "42sh.h"

char	*g_cmd;

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
  if (SIZE_BUFFER <= 0 ||
      (cmd = malloc(sizeof(char) * SIZE_BUFFER)) == NULL)
    return (NULL);
  cmd[0] = '\0';
  get_pos_curser(&param->x, &param->y);
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
  g_cmd = NULL;
  g_cmd = init_read_cmd(g_cmd, param);
  ret = 1;
  while (ret > 0)
    {
      signal(SIGWINCH, gere_change_window);
      if ((ret = read(0, buff, 10)) == -1)
	return (NULL);
      buff[ret % 10] = '\0';
      if (buff[0] == CTRLD && buff[1] == '\0')
	return (NULL);
      if (buff[0] == '\n' && buff[1] == '\0')
	{
	  my_putstr("\n", 1, 1);
	  return (g_cmd);
	}
      if (get_window_size(g_cmd, param->begin_pos_x) == 1 &&
	  gere_keyboard(buff, g_cmd, param) == 1)
	{
	  add_caractere(g_cmd, param, buff[0]);
	  view(g_cmd, param);
	}
    }
  return (g_cmd);
}
