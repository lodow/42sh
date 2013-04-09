/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Apr  9 15:37:33 2013 maxime lavandier
*/

#include "../../include/42sh.h"

char	*builtin_cd_env(t_sh *shell, char *path, char *temp)
{
  if (get_envvar("PWD", shell->env) != 0)
    rm_ptr_f_tab((void **) shell->env, "PWD");
  shell->env = (char **) add_ptr_t_tab((void **)shell->env, path);
  free(path);
  return (temp);
}

void		builtin_cd(t_sh *shell, t_cmd *cmd)
{
  char		temp[4096];
  static char	*prec;
  char		*path;

  getcwd(temp, 4095);
  if (cmd->argv[1] != 0 && cmd->argv[1][0] == '-' &&
      cmd->argv[1][1] == 0 && prec != 0)
    {
      chdir(prec);
      path = malloc(my_strlen(prec) + 4);
      my_strncpy(path, "PWD=", -1);
      my_strncpy(&(path[4]), prec, -1);
    }
  else if (cmd->argv[1] != 0)
    {
      chdir(cmd->argv[1]);
      path = malloc(my_strlen(cmd->argv[1]) + 5);
      my_strncpy(path, "PWD=", -1);
      my_strncpy(&(path[4]), cmd->argv[1], -1);
    }
  else
    return ;
  free(prec);
  prec = builtin_cd_env(shell, path, temp);
}
