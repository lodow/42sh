/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun May 19 00:30:24 2013 maxime lavandier
*/

#include "42sh.h"

char		*builtin_cd_getcwd()
{
  char		*res;

  if ((res = getcwd(NULL, 0)) == NULL)
    my_perror("Getcwd");
  return (res);
}

void		builtin_cd(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  char		*cur_path;
  char		*new_path;
  char		*tmp_path;
  char		*usr_path;

  if ((usr_path = cmd->argv[1]) == NULL)
    usr_path = get_envvar("HOME", shell->env);
  if ((cur_path = builtin_cd_getcwd()) == NULL)
    return ;
  if (my_strncmp(usr_path, "-", -1) == 0)
    {
      if (((tmp_path = get_envvar("OLD_PWD", shell->env)) == NULL)
          || (check_perror("cd", chdir(tmp_path)) == -1))
        return ;
    }
  else if ((usr_path != NULL)
           && (check_perror("cd", chdir(usr_path)) == -1))
    return ;
  if ((new_path = builtin_cd_getcwd()) == NULL)
    return ;
  shell->env = add_change_env(shell->env, "PWD", new_path);
  shell->env = add_change_env(shell->env, "OLD_PWD", cur_path);
  free(new_path);
  free(cur_path);
}
