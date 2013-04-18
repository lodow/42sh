/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Apr 10 08:46:01 2013 remi robert
*/

#include "42sh.h"

void	builtin_exit(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  exit_shell(shell);
  if (cmd->argv[1] == NULL)
    my_exit(0);
  else
    my_exit(my_getnbr(cmd->argv[1]));
}
