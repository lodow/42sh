/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Apr 10 08:46:01 2013 remi robert
*/

#include "../../include/42sh.h"

void	builtin_exit(t_sh *shell, t_cmd *cmd)
{
  if (cmd == NULL || cmd->argv == NULL || cmd->argv[0] == NULL)
    return ;
  reset_mod(shell->param.t);
  if (cmd->argv[1] == NULL)
    exit(0);
  else
    exit(my_getnbr(cmd->argv[1]));
}
