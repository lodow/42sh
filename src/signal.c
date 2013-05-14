/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "42sh.h"

t_sh		*get_sh_info(t_sh *sh)
{
  static t_sh	*shell;

  if (sh != NULL)
    shell = sh;
  return (shell);
}

void	init_sig()
{
  signal(SIGTTOU, &sig_handler);
  signal(SIGTTIN, &sig_handler);
  signal(SIGINT, &sig_handler);
  signal(SIGTSTP, &sig_handler);
  signal(SIGCHLD, &sig_handler);
  signal(SIGHUP, &sig_handler);
  signal(SIGTERM, &sig_handler);
}

void	sig_handler(int sig)
{
  t_sh	*shell;

  shell = get_sh_info(NULL);
  SETFLAG(shell->signal, FLAGPOS(sig));
  if (sig == SIGINT)
    {
      my_putstr("\n", 1, -1);
      my_putstr(shell->param.str_prompt, 1, -1);
    }
  if ((sig == SIGHUP) || (sig == SIGTERM))
    close(0);
  init_sig();
}

void	call_signal_func(t_sh *shell, int chld_sig)
{
  if (chld_sig == SIGTSTP)
    no_fg_jobs_status(shell);
  wait_all_jobs(shell);
  shell->signal = 0;
}
