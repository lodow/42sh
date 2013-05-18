/*
** read_cmd.c for read_cmd in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 16:03:47 2013 remi robert
** Last update Sat May 18 18:59:02 2013 remi robert
*/

#include "42sh.h"

void	init_prompt_cmd(char *prompt, char *cmd, t_param *param)
{
  int	indice;

  free(param->str_prompt);
  param->str_prompt = NULL;
  if ((param->str_prompt = malloc(my_strlen(prompt) + 1)) == NULL)
    return ;
  indice = -1;
  while (prompt[++indice] != '\0')
    param->str_prompt[indice] = prompt[indice];
  param->str_prompt[indice] = '\0';
}

char	*init_read_cmd(char *prompt, char *cmd, t_param *param)
{
  if (prompt != NULL)
    init_prompt_cmd(prompt, cmd, param);
  if (mod_raw(param->fd_tty) == EXIT_FAILURE)
    {
      my_putstr("Error mod_raw termcap\n", 2, -1);
      return (NULL);
    }
  my_putstr(param->str_prompt, 1, -1);
  if (SIZE_BUFFER <= 0 ||
      (cmd = malloc(sizeof(char) * SIZE_BUFFER)) == NULL)
    return (NULL);
  cmd[0] = '\0';
  get_pos_curser(&param->x, &param->y, param->fd_tty);
  param->begin_pos_x = param->x;
  param->begin_pos_y = param->y;
  param->pos = 0;
  param->pos_history = 0;
  return (cmd);
}

char	*loop_cmd(char *prompt, t_param *param, t_history **history)
{
  int	ret;
  char	buff[10];

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
        return (return_string(param->cmd, param, history));
      if (get_window_size(param->cmd, param->begin_pos_x) == 1 &&
          gere_keyboard(buff, param->cmd, param, history) == 1)
        {
          add_caractere(param->cmd, param, buff[0]);
          view(param->cmd, param);
        }
    }
  return (param->cmd);
}

char	*read_cmd(char *prompt, t_param *param, t_history **history)
{
  if (isatty(0) != 1)
    param->env = 0;
  if (param->env == 0)
    {
      my_putstr(prompt, 1, -1);
      return (get_next_line(0));
    }
  param->cmd = NULL;
  if ((param->cmd = init_read_cmd(prompt, param->cmd, param)) == NULL)
    return (NULL);
  return (loop_cmd(prompt, param, history));
}
