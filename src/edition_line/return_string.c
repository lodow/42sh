/*
** return_string.c for return_string in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 16 11:18:24 2013 remi robert
** Last update Sat May 25 23:06:52 2013 Adrien Della Maggiora
*/

#include "42sh.h"

char	*return_string(char *cmd, t_param *param, t_history **history)
{
  my_putstr("\n", 1, 1);
  if (reset_save_mod(RESTORE, param->fd_tty) == EXIT_FAILURE)
    my_putstr("Error SAVE termcap\n", 2, -1);
  return (cmd);
}
