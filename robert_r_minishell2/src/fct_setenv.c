/*
** setenv.c for setenv in /home/remi/Projet/minishell/new_shell/env/builtins
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Jan 31 04:01:42 2013 remi robert
** Last update Thu Mar  7 19:54:11 2013 remi
*/

#include "my_func.h"

int	fct_setenv(t_list **ptete, t_cmd *cmd)
{
  char	*buff;

  if (cmd == NULL || cmd->cmd == NULL ||
      cmd->cmd[0] == NULL || cmd->cmd[1] == NULL)
    {
      fct_env(ptete, cmd);
      return (0);
    }
  if (cmd->cmd[2] != NULL)
    buff = str_assemble(cmd->cmd[1], cmd->cmd[2], '=');
  else
    buff = str_assemble(cmd->cmd[1], "", '=');
  fct_unsetenv(ptete, cmd);
  add_to_list(ptete, buff);
  free(buff);
  return (0);
}
