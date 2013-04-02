/*
** main.c for 42sh in /home/maxime/Bureau/projet/actu/42sh
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:31:22 2013 maxime lavandier
** Last update Fri Mar 29 14:58:26 2013 maxime lavandier
*/

#include "../include/42sh.h"

char	**get_path(char **envp)
{
  char	**paths;

  paths = my_str_to_wordtab(get_envvar("PATH", envp), ':', 1);
  if (paths == NULL)
    {
      // if you want to set a default path if none, it's here!
    }
  return (paths);
}

int	init_shell(t_sh *shell, char **main_env)
{
  get_sh_info(shell);
  init_builtins(shell);
  if (((shell->env = cpy_env(main_env)) == NULL)
      || ((shell->path = get_path(shell->env)) == NULL))
    return (-1);

  //shell->pid.sid = setsid(); <- not sure if it's a good idea.
  //if it is don't forget to check it
  if ((shell->pid.pid = getpid() == -1)
      || (shell->pid.pgid = getpgid(shell->pid.pgid) == -1))
    return (-1);
  shell->process_group = NULL;
  shell->forground = NULL;
  return (0);
}

int	main(int ac, char **av, char **main_env)
{
  t_sh	shell;

  init_shell(&shell, main_env);
  if (shell.env != NULL)
    {
      user_loop(&shell);
    }
  //free shell
  free_ptr_tab((void**)shell.env);
  return (0);
}
