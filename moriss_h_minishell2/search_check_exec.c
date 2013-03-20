/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

char	*exec_full_path(char *exec, char **paths)
{
  char	*fpaths;
  int	len;

  fpaths = NULL;
  while ((exec != NULL) && (paths != NULL) && (paths[0] != NULL))
    {
      len = my_strlen(exec) + my_strlen(paths[0]) + 2;
      if ((fpaths = malloc(sizeof(char) * len)) == NULL)
        return (my_strdup(exec));
      my_strncpy(fpaths, paths[0], -1);
      my_strncpy(&(fpaths[my_strlen(paths[0])]), "/", -1);
      my_strncpy(&(fpaths[my_strlen(paths[0]) + 1]), exec, -1);
      if ((access(fpaths, F_OK) == 0) && access(fpaths, X_OK) == 0)
        return (fpaths);
      free(fpaths);
      paths = &paths[1];
    }
  return (my_strdup(exec));
}

void	print_env(char **envp)
{
  while (envp[0] != NULL)
    {
      my_putstr(envp[0], 1, -1);
      my_putstr("\n", 1, -1);
      envp = &envp[1];
    }
}

int	is_executable(t_prg *cmd)
{
  if ((cmd->argv == NULL) || (cmd->argv[0] == NULL)
      || (cmd->argv[0][0] == '\0') || (cmd->prg == NULL)
      || (access(cmd->prg, F_OK) == -1) || (access(cmd->prg, X_OK) == -1))
    return (0);
  return (1);
}
