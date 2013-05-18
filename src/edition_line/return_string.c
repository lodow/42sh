/*
** return_string.c for return_string in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 16 11:18:24 2013 remi robert

*/

#include "42sh.h"

char	*return_string(char *cmd, t_param *param, t_history **history)
{
  parseur_history(cmd);
  if (cmd[0] != '\0' && cmd[0] != '\n')
    add_history(history, cmd);
  my_putstr("\n", 1, 1);
  if (reset_save_mod(RESTORE, param->fd_tty) == EXIT_FAILURE)
    my_putstr("Error SAVE termcap\n", 2, -1);
  return (cmd);
}
