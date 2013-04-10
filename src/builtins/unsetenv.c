/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Apr 10 02:23:48 2013 maxime lavandier
*/

#include "../../include/42sh.h"

void	builtin_unsetenv(t_sh *shell, t_cmd *cmd)
{
  char	*temp;

  if (cmd->argv[1] == NULL)
    my_putstr("Unsetenv: missing argument\n", 2, -1);
  if ((temp = get_envvar(cmd->argv[1], shell->env)) != NULL)
    rm_ptr_f_tab((void **) shell->env, temp - my_strlen(cmd->argv[1]) - 1);
  if (my_strncmp(cmd->argv[1], "PATH", -1) == 0)
    {
      free_ptr_tab((void **) shell->path);
      shell->path = 0;
    }
}
