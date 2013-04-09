/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Apr  9 23:41:56 2013 maxime lavandier
*/

#include "../../include/42sh.h"

char	*builtin_cd_env(t_sh *shell, char *path, char *temp)
{
  if (get_envvar("PWD", shell->env) != NULL)
    rm_ptr_f_tab((void **)shell->env, get_envvar("PWD", shell->env) - 4);
  shell->env = (char **) add_ptr_t_tab((void **)shell->env, path);
  return (temp);
}

void		builtin_cd(t_sh *shell, t_cmd *cmd)
{
  char		temp[4096];
  char		*path;
  char		*old_pwd;

  getcwd(temp, 4095);
  if ((cmd->argv[1] != NULL) && (my_strncmp(cmd->argv[1], "-", -1) == 0)
      && (old_pwd = get_envvar("OLD_PWD", shell->env)) != NULL)
    {
      chdir(old_pwd);
      rm_ptr_f_tab((void **) shell->env, (void *) old_pwd - 8);
      path = malloc(my_strlen(temp) + 9);
      my_strncpy(path, "OLD_PWD=", -1);
      my_strncpy(&(path[8]), old_pwd, -1);
    }
  else if (cmd->argv[1] != NULL)
    {
      chdir(cmd->argv[1]);
      getcwd(temp, 4095);
      path = malloc(my_strlen(temp) + 5);
      my_strncpy(path, "PWD=", -1);
      my_strncpy(&(path[4]), temp, -1);
    }
  else
    return ;
  builtin_cd_env(shell, path, temp);
}
