/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Apr  9 15:53:25 2013 maxime lavandier
*/

#include "../../include/42sh.h"

void	builtin_unsetenv(t_sh *shell, t_cmd *cmd)
{
  if (cmd->argv[1] == 0)
    write(1, "unsetenv: Trop peu d'arguments.\n", 32);
  if (get_envvar(cmd->argv[1], shell->env) != 0)
    rm_ptr_f_tab((void **) shell->env, cmd->argv[1]);
}
