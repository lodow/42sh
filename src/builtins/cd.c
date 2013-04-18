/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Apr 10 01:50:44 2013 maxime lavandier
*/

#include "42sh.h"

char	*builtin_cd_env(t_sh *shell, char *path, char *temp)
{
  getcwd(temp, 4095);
  path = malloc(my_strlen(temp) + 5);
  my_strncpy(path, "PWD=", -1);
  my_strncpy(&(path[4]), temp, -1);
  if (get_envvar("PWD", shell->env) != NULL)
    rm_ptr_f_tab((void **)shell->env, get_envvar("PWD", shell->env) - 4);
  shell->env = (char **) add_ptr_t_tab((void **)shell->env, path);
  return (temp);
}

void		builtin_cd(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  char		temp[4096];
  char		*path;
  char		*old_pwd;

  getcwd(temp, 4095);
  old_pwd = get_envvar("OLD_PWD", shell->env);
  if ((cmd->argv[1] != NULL) && (my_strncmp(cmd->argv[1], "-", -1) == 0)
      && old_pwd != NULL)
    {
      chdir(old_pwd);
      rm_ptr_f_tab((void **) shell->env, (void *) old_pwd - 8);
      path = malloc(my_strlen(temp) + 9);
      my_strncpy(path, "OLD_PWD=", -1);
      my_strncpy(&(path[8]), temp, -1);
      shell->env = (char **) add_ptr_t_tab((void **)shell->env, path);
    }
  else if (cmd->argv[1] != NULL)
    {
      if (old_pwd != NULL)
        rm_ptr_f_tab((void **) shell->env, (void *) old_pwd - 8);
      path = malloc(my_strlen(temp) + 9);
      my_strncpy(path, "OLD_PWD=", -1);
      my_strncpy(&(path[8]), temp, -1);
      shell->env = (char **) add_ptr_t_tab((void **)shell->env, path);
      chdir(cmd->argv[1]);
    }
  else
    return ;
  builtin_cd_env(shell, path, temp);
}
