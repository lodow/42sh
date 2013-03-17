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

int	special_cmd(t_prg *cmd, char ***envp, int exec)
{
  void	(*(f[5]))(t_prg * cmd, char ***envp);
  char	*builtin[5];
  int	i;

  i = 0;
  builtin[0] = "exit";
  f[0] = &builtin_exit;
  builtin[1] = "cd";
  f[1] = &builtin_cd;
  builtin[2] = "env";
  f[2] = &builtin_env;
  builtin[3] = "unsetenv";
  f[3] = &builtin_unsetenv;
  builtin[4] = "setenv";
  f[4] = &builtin_setenv;
  while ((cmd->argv != NULL) && (i < 5))
    if (my_strncmp(cmd->argv[0], builtin[i], -1) == 0)
      {
        if (exec)
          f[i](cmd, envp);
        return (1);
      }
    else
      i++;
  return (0);
}

int	is_executable(t_prg *cmd)
{
  if ((cmd->argv == NULL) || (cmd->argv[0] == NULL)
      || (cmd->argv[0][0] == '\0') || (cmd->prg == NULL)
      || (access(cmd->prg, F_OK) == -1) || (access(cmd->prg, X_OK) == -1))
    return (0);
  return (1);
}
