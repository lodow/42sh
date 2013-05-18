/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat May 18 23:28:49 2013 remi robert
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
  /*  signal(SIGTTOU, &sig_handler);
    signal(SIGTTIN, &sig_handler);*/
  signal(SIGWINCH, &sig_handler);
  signal(SIGINT, &sig_handler);
  signal(SIGTSTP, &sig_handler);
  signal(SIGCHLD, &sig_handler);
  signal(SIGHUP, &sig_handler);
  signal(SIGTERM, &sig_handler);
  signal(SIGUSR1, &sig_handler);
  signal(SIGUSR2, &sig_handler);
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
      if (shell->param.fallback == 1)
	shell->param.cmd[0] = '\0';
      else
	shell->param.cmd = NULL;
      shell->param.pos = 0;
      if (shell->param.fallback == 1)
	{
	  refresh_view(shell->param.cmd, &(shell->param));
	  view(shell->param.cmd, &(shell->param));
	}
    }
  if (sig == SIGWINCH)
    gere_change_window(SIGWINCH);
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
