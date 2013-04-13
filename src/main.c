/*
** main.c for 42sh in /home/maxime/Bureau/projet/actu/42sh
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:31:22 2013 maxime lavandier
** Last update Fri Apr 12 19:28:35 2013 remi robert
*/

#include "../include/42sh.h"

char	**get_path(char **envp)
{
  char	**paths;

  paths = str_to_wordtab(get_envvar("PATH", envp), ":", 0);
  if (paths == NULL)
    {
      // if you want to set a default path if none, it's here!
    }
  return (paths);
}

int		init_shell(t_sh *shell, char **main_env)
{
  get_sh_info(shell);
  init_builtins(shell);
  if (((shell->env = cpy_env(main_env)) == NULL)
      || ((shell->path = get_path(shell->env)) == NULL) ||
      (shell->history = malloc(sizeof(t_history))) == NULL)
    return (-1);
  if (main_env == NULL || recup_path(main_env) == 0 ||
      init_tab_line(&(shell->param)) == 0)
    return (-1);
  //init_pos_line(&(shell->param));
  //shell->pid.sid = setsid(); <- not sure if it's a good idea.
  //if it is don't forget to check it
  if (((shell->pid.pid = getpid()) == -1)
      || ((shell->pid.pgid = getpgid(shell->pid.pid)) == -1))
    return (-1);
  shell->history = NULL;
  shell->process_group = NULL;
  shell->env = add_change_env(shell->env, "PS1", "${LOGNAME} ${PWD} $ "); //default path
  shell->alias_tab = NULL;
  shell->signal = 0;
  //Load a configu file here
  return (0);
}

int		main(int ac, char **av, char **main_env)
{
  t_sh		shell;

  signal(SIGTTOU, &sig_handler);
  signal(SIGTTIN, &sig_handler);
  signal(SIGINT, &sig_handler);
  signal(SIGTSTP, &sig_handler);
  signal(SIGCHLD, &sig_handler);
  if (init_shell(&shell, main_env) == -1)
    return (0);
  if (shell.env != NULL)
    {
      user_loop(&shell);
    }
  //free shell
  free_ptr_tab((void**)shell.env);
  return (0);
}
