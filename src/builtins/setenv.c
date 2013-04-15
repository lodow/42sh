/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Apr 10 02:23:18 2013 maxime lavandier
*/

#include "42sh.h"

void	builtin_setenv(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  if (cmd->argv[1] == NULL)
    {
      builtin_env(cmd, fd, shell);
      return ;
    }
  shell->env = add_change_env(shell->env, cmd->argv[1], cmd->argv[2]);
  if (my_strncmp(cmd->argv[1], "PATH", -1) == 0)
    shell->path = get_path(shell->env);
}
