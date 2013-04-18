/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu Apr 18 16:54:58 2013 maxime lavandier
*/

#include "42sh.h"


void	env_exec(char *cmd, char **argv, char **env)
{
  //do something
}

void	env_unset_and_exec(char *cmd, char **argv, t_sh *shell, char *to_unset)
{
  char	*old_unset;
  char	*new_unset;

  old_unset = get_envvar(to_unset, shell->env);
  if (old_unset == NULL)
    {
      if ((new_unset = malloc(my_strlen(old_unset))) == NULL)
	{
	  my_putstr("malloc error\n", 1, -1);
	  return ;
	}
      my_strncpy(new_unset, old_unset - (strlen(to_unset) + 1), -1);
      rm_ptr_f_tab((void **) shell->env, (void *) old_unset - (strlen(to_unset) + 1));
      env_exec(cmd, argv, shell->env);
      shell->env = (char **) add_ptr_t_tab((void **) shell->env, new_unset);
    }
}

void	env_chose_option(char *path, char **argv, t_sh *shell)
{
  char	ignore_env;
  char	*unset;
  int	i;

  i = 0;
  unset = NULL;
  while (argv[i] != NULL && argv[i][0] == '-')
    {
      if (my_strncmp(argv[i], "-i", -1) == 0)
	ignore_env = 1;
      else if (my_strncmp(argv[i], "-u", -1))
	unset = argv[i + 1];
      i++;
    }
  if (ignore_env == 1)
    env_exec(argv[i], &(argv[i]), 0);
  else if (unset != NULL)
    env_unset_and_exec(argv[i + 1], &(argv[i + 1]), shell, unset);
  else
    env_exec(argv[i], &(argv[i]), shell->env);
}

int	builtin_env_print(char *path, char **argv, t_sh *shell)
{
  int	i;
  char	**envp;

  if (argv[1] != NULL && my_strncmp(argv[1], "-0", -1) != 0)
    env_chose_option(path, argv, shell);
  else
    {
      i = 0;
      envp = shell->env;
      if (envp != NULL)
	while (envp[i] != NULL)
	  {
	    my_putstr(envp[i], 1, -1);
	    if (argv[1] == NULL)
	      my_putstr("\n", 1, -1);
	    i++;
	  }
    }
  return (0);
}

void	builtin_env(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
    exec_process(cmd, fd, shell, &builtin_env_print);
}
