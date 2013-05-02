/*
** main.c for main in /home/remi/Projet/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 14:13:14 2013 remi
** Last update Thu May  2 21:09:11 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

int	recup_path(char **envp)
{
  char	*term;

  if ((term = get_envvar("TERM", envp)) == NULL)
    return (FALSE);
  if (tgetent(NULL, term) != 1)
    return (FALSE);
  return (OK);
}

int	init_tab_line(t_param *param)
{
  if ((param->fd_tty = open("/dev/tty", O_RDWR)) == -1)
    param->fd_tty = 1;
  param->str_prompt = NULL;
  param->string = NULL;
  param->len_string = 0;
  param->buff_copy[0] = END;
  param->pos_history = 0;
  if (tcgetattr(param->fd_tty, &(param->t)) == -1)
    return (FALSE);
  return (OK);
}

int	init_pos_line(t_param *param)
{
  if (mod_raw(param->fd_tty) == EXIT_FAILURE)
    return (0);
  get_pos_curser(&(param->begin_pos.x), &(param->begin_pos.y), param->fd_tty);
  param->current_pos.x = param->begin_pos.x;
  param->current_pos.y = param->begin_pos.y;
  curseur(param->current_pos.x, param->current_pos.y, param->fd_tty);
  return (1);
}
