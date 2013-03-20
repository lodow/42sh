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

void	builtin_exit(t_prg *cmd, t_sh_info *shell)
{
  int	tmp;

  tmp = my_getnbr(cmd->argv[1]);
  free_prg(cmd);
  destroy_envp(shell->envp);
  exit(tmp);
}

void	builtin_cd(t_prg *cmd, t_sh_info *shell)
{
  char	*path;

  path = cmd->argv[1];
  if (path == NULL)
    path = get_envvar("HOME", shell->envp);
  else if (my_strncmp(cmd->argv[1], "-", -1) == 0)
    path = get_envvar("OLDPWD", shell->envp);
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
      if (get_envvar("PWD", shell->envp) != NULL)
        shell->envp = add_change_env(shell->envp, "OLDPWD",
                                     get_envvar("PWD", shell->envp));
      pwd_recalc(get_envvar("PWD", shell->envp), path, &(shell->envp));
      free(path);
    }
}

void	builtin_env(t_prg *cmd, t_sh_info *shell)
{
  print_env(shell->envp);
}

void	builtin_unsetenv(t_prg *cmd, t_sh_info *shell)
{
  rm_env(shell->envp, cmd->argv[1]);
}

void	builtin_setenv(t_prg *cmd, t_sh_info *shell)
{
  if ((cmd->argv[1] != NULL) && (cmd->argv[2] != NULL)
      && (cmd->argv[1][0] != '\0') && (cmd->argv[2][0] != '\0'))
    shell->envp = add_change_env(shell->envp, cmd->argv[1], cmd->argv[2]);
}
