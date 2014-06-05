#include "42sh.h"

char		*builtin_cd_getcwd()
{
  char		*res;

  if ((res = getcwd(NULL, 0)) == NULL)
    my_perror("Getcwd");
  return (res);
}

int	builtin_cd_return_value(int *return_value, int ret_val, int val)
{
  *return_value = val;
  return (ret_val);
}

void	builtin_cd_change_var(t_sh *shell, char *new_path, char *cur_path)
{
  shell->env = add_change_env(shell->env, "PWD", new_path);
  shell->env = add_change_env(shell->env, "OLD_PWD", cur_path);
  free(new_path);
  free(cur_path);
}

int		builtin_cd(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  char		*cur_path;
  char		*new_path;
  char		*tmp_path;
  char		*usr_path;

  if ((usr_path = cmd->argv[1]) == NULL)
    usr_path = get_envvar("HOME", shell->env);
  if (((cur_path = builtin_cd_getcwd()) == NULL)
      || (fd->stdin != 0) || (fd->stdout != 1))
    return (builtin_cd_return_value(&cmd->return_value, 1, 1));
  if (my_strncmp(usr_path, "-", -1) == 0)
    {
      if (((tmp_path = get_envvar("OLD_PWD", shell->env)) == NULL)
          || (check_perror("cd", chdir(tmp_path)) == -1))
	return (builtin_cd_return_value(&cmd->return_value, 1, 1));
    }
  else if ((usr_path != NULL)
           && (check_perror("cd", chdir(usr_path)) == -1))
    return (builtin_cd_return_value(&cmd->return_value, 1, 1));
  if ((new_path = builtin_cd_getcwd()) == NULL)
    return (builtin_cd_return_value(&cmd->return_value, 1, 1));
  builtin_cd_change_var(shell, new_path, cur_path);
  return (builtin_cd_return_value(&cmd->return_value, 0, 0));
}
