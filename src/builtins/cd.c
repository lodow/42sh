/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed May 15 16:07:10 2013 maxime lavandier
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

char	*cd_new_dir(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  char		temp[4096];
  char		*path;
  char		*old_pwd;

  getcwd(temp, 4095);
  old_pwd = get_envvar("OLD_PWD", shell->env);
  if (chdir(cmd->argv[1]))
    {
      my_perror("cd ");
      return (NULL);
    }
  if (old_pwd != NULL)
    rm_ptr_f_tab((void **) shell->env, (void *) old_pwd - 8);
  path = malloc(my_strlen(temp) + 9);
  if (path != NULL)
    {
      my_strncpy(path, "OLD_PWD=", -1);
      my_strncpy(&(path[8]), temp, -1);
      shell->env = (char **) add_ptr_t_tab((void **)shell->env, path);
    }
  return (path);
}

void		builtin_cd(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  char		temp[4096];
  char		*path;
  char		*old_pwd;

  getcwd(temp, 4095);
  temp[4095] = '\0';
  path = NULL;
  old_pwd = get_envvar("OLD_PWD", shell->env);
  if ((cmd->argv[1] != NULL) && (my_strncmp(cmd->argv[1], "-", -1) == 0)
      && old_pwd != NULL)
    {
      if (chdir(old_pwd) == -1)
        return ;
      rm_ptr_f_tab((void **) shell->env, (void *) old_pwd - 8);
      path = malloc(my_strlen(temp) + 9);
      my_strncpy(path, "OLD_PWD=", -1);
      if (path != NULL)
	my_strncpy(&(path[8]), temp, -1);
      shell->env = (char **) add_ptr_t_tab((void **)shell->env, path);
    }
  else if (cmd->argv[1] != NULL)
    path = cd_new_dir(cmd, fd, shell);
  if (path != NULL)
    builtin_cd_env(shell, path, temp);
}
