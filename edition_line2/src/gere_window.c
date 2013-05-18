/*
** gere_window.c for gere_window in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 10 08:43:23 2013 remi robert
** Last update Fri May 10 08:45:38 2013 remi robert
*/

#include "termcap.h"

int	get_window_size(char *cmd, int add_prompt)
{
  int	size;
  int	size_cmd;

  size_cmd = my_strlen(cmd) + add_prompt;
  size = return_x() * return_y();
  if (size <= size_cmd)
    return (0);
  return (1);
}

void	my_putstr_view(char *cmd, int add_prompt, t_param *param)
{
  int	size;
  int	size_cmd;

  size_cmd = my_strlen(cmd) + add_prompt;
  size = return_x() * return_y();
  if (size <= size_cmd && size >= my_strlen("Window too small"))
    my_putstr("Window too small");
  else
    {
      my_putstr(cmd);
      curseur(param->x, param->y);
    }
}
