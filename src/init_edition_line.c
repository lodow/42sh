/*
** init_edition_line.c for init_edition_line in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed May 15 08:47:35 2013 remi robert
** Last update Wed May 15 13:49:55 2013 remi robert
*/

#include "42sh.h"

int	init_edition_line(char **env, t_param *param)
{
  if ((param->fd_tty = open("/dev/tty", O_RDWR)) == -1 ||
      verif_env(env) == EXIT_FAILURE)
    return (0);
  param->cmd = NULL;
  my_putstr_termcap(param->fd_tty, NULL);
  if (verif_env(env) == EXIT_FAILURE)
    {
      my_putstr("Error environnement termcap\n", 2, -1);
      return (0);
    }
  if (reset_save_mod(SAVE, param->fd_tty) == EXIT_FAILURE)
    {
      my_putstr("Error SAVE termcap\n", 2, -1);
      return (0);
    }
  if (mod_raw(param->fd_tty) == EXIT_FAILURE)
    {
      my_putstr("Error mod_raw termcap\n", 2, -1);
      return (0);
    }
  init_capacity_termcap(&(param->termcap));
  return (1);
}
