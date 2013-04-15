/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Apr 10 02:23:48 2013 maxime lavandier
*/

#include "42sh.h"

void	builtin_unsetenv(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  if (cmd->argv[1] == NULL)
    my_putstr("Unsetenv: missing argument\n", 2, -1);
  rm_env(shell->env, cmd->argv[1]);
  if (my_strncmp(cmd->argv[1], "PATH", -1) == 0)
    {
      free_ptr_tab((void **) shell->path);
      shell->path = NULL;
    }
}
