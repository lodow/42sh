/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun May 19 09:42:31 2013 Hugues
*/

#include "42sh.h"

t_sh		*get_sh_info(t_sh *sh)
{
  static t_sh	*shell;

  if (sh != NULL)
    shell = sh;
  return (shell);
}

void	init_sig(void *handler)
{
  /*  signal(SIGTTOU, handler);
    signal(SIGTTIN, handler);*/
  signal(SIGWINCH, handler);
  signal(SIGINT, handler);
  signal(SIGTSTP, handler);
  signal(SIGCHLD, handler);
  signal(SIGHUP, handler);
  signal(SIGTERM, handler);
  signal(SIGUSR1, handler);
  signal(SIGUSR2, handler);
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
        {
          shell->param.cmd[0] = '\0';
          shell->param.pos = 0;
          refresh_view(shell->param.cmd, &(shell->param));
          view(shell->param.cmd, &(shell->param));
        }
    }
  if (sig == SIGWINCH)
    gere_change_window(SIGWINCH);
  if ((sig == SIGHUP) || (sig == SIGTERM))
    {
      SETFLAG(shell->beepbeepexit, FLAGPOS(EXIT_F_POS));
      close(0);
    }
  init_sig(&sig_handler);
}

void	call_signal_func(t_sh *shell, int chld_sig)
{
  if ((chld_sig == SIGTSTP) || (chld_sig == SIGSTOP))
    no_fg_jobs_status(shell);
  wait_all_jobs(shell);
  rm_all_terminated_grp(shell);
  shell->signal = 0;
}
