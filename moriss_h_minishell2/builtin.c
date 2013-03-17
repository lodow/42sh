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

void	builtin_exit(t_prg *cmd, char ***envp)
{
  int	tmp;

  tmp = my_getnbr(cmd->argv[1]);
  free_prg(cmd);
  destroy_envp(*envp);
  exit(tmp);
}

void	builtin_cd(t_prg *cmd, char ***envp)
{
  char	*path;

  path = cmd->argv[1];
  if (path == NULL)
    path = get_envvar("HOME", *envp);
  else if (my_strncmp(cmd->argv[1], "-", -1) == 0)
    path = get_envvar("OLDPWD", *envp);
  if ((path == NULL) || (chdir(path) != 0))
    {
      my_putstr("cd can't find ", 2, -1);
      my_putstr(path, 2, -1);
      my_putstr("\n", 2, -1);
    }
  else
    {
      if ((path = my_strdup(path)) == NULL)
        return ;
      if (get_envvar("PWD", *envp) != NULL)
        (*envp) = add_change_env(*envp, "OLDPWD", get_envvar("PWD", *envp));
      pwd_recalc(get_envvar("PWD", *envp), path, envp);
      free(path);
    }
}

void	builtin_env(t_prg *cmd, char ***envp)
{
  print_env(*envp);
}

void	builtin_unsetenv(t_prg *cmd, char ***envp)
{
  rm_env(*envp, cmd->argv[1]);
}

void	builtin_setenv(t_prg *cmd, char ***envp)
{
  if ((cmd->argv[1] != NULL) && (cmd->argv[2] != NULL)
      && (cmd->argv[1][0] != '\0') && (cmd->argv[2][0] != '\0'))
    (*envp) = add_change_env(*envp, cmd->argv[1], cmd->argv[2]);
}
