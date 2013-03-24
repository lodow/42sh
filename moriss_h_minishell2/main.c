/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec 29 20:41:37 2012 Hugues
*/

#include "include.h"

int		main(int argc, char **argv, char **envp)
{
  t_sh_info	shell;

  if (init_shell_f_jobs(&shell) == -1)
    return (-1);
  shell.envp = cpy_env(envp);
  shell.envp = add_change_env(shell.envp, "PS1", "${LOGNAME} ${PWD} $ ");
  load_conf_file(".mysh", &(shell.envp));
  signal(SIGTTOU, &handle_signal);
  signal(SIGTTIN, &handle_signal);
  signal(SIGINT, &handle_signal);
  signal(SIGTSTP, &handle_signal);
  if (shell.envp != NULL)
    {
      getlaunch_prg(&shell);
      destroy_envp(shell.envp);
    }
  else
    my_putstr("Malloc failed\n", 2, -1);
  return (0);
}
