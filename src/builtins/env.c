/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Apr 15 20:32:37 2013 maxime lavandier
*/

#include "42sh.h"

int	builtin_env_print(char *path, char **argv, t_sh *shell)
{
  int	i;
  char	**envp;

  i = 0;
  envp = shell->env;
  if (envp != NULL)
    while (envp[i] != NULL)
      {
        my_putstr(envp[i], 1, -1);
        my_putstr("\n", 1, -1);
        i++;
      }
  my_exit(0);
  return (-1);
}

void	builtin_env(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  if (cmd->argv[1] == 0)
    exec_process(cmd, fd, shell, &builtin_env_print);
  else
    printf ("pas encore\n");
}
