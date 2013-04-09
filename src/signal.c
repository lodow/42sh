/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "../include/42sh.h"

t_sh		*get_sh_info(t_sh *sh)
{
  static t_sh	*shell;

  if (sh != NULL)
    shell = sh;
  return (shell);
}

void	sig_handler(int sig)
{
  t_sh	*shell;

  shell = get_sh_info(NULL);
  SETFLAG(shell->signal, FLAGPOS(sig));
  signal(SIGTTOU, &sig_handler);
  signal(SIGTTIN, &sig_handler);
  signal(SIGINT, &sig_handler);
  signal(SIGTSTP, &sig_handler);
  signal(SIGCHLD, &sig_handler);
}

void	call_signal_func(t_sh *shell, int chld_sig)
{
  if (GETFLAG(shell->signal, FLAGPOS(SIGCHLD)))
    {
      if (chld_sig == SIGTSTP)
        update_jobs_status(shell);
      wait_all_jobs(shell, shell->process_group);
    }
  if (GETFLAG(shell->signal, FLAGPOS(SIGINT)))
    {
      my_putstr("\n", 1, -1);
      prompt(shell);
    }
  shell->signal = 0;
}
