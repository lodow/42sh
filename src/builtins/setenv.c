/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Apr  9 15:42:01 2013 maxime lavandier
*/

#include "../../include/42sh.h"

void	builtin_setenv(t_sh *shell, t_cmd *cmd)
{
  char	*temp;

  if (cmd->argv[1] == 0)
    {
      builtin_env(shell, cmd);
      return ;
    }
  if (get_envvar(cmd->argv[1], shell->env) != 0)
    rm_ptr_f_tab((void **) shell->env, cmd->argv[1]);
  temp = malloc(my_strlen(cmd->argv[1]) + my_strlen(cmd->argv[2]) + 2);
  my_strncpy(temp, cmd->argv[1], -1);
  my_strncpy(&(temp[my_strlen(temp)]), "=", -1);
  my_strncpy(&(temp[my_strlen(temp)]), cmd->argv[2], -1);
  shell->env = (char **) add_ptr_t_tab((void **) shell->env, temp);
}
