/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Fri May 24 13:55:40 2013 luc sinet
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
  signal(SIGTTIN, handler);
  signal(SIGTTOU, handler);
  signal(SIGWINCH, handler);
  signal(SIGINT, handler);
  signal(SIGTSTP, handler);
  signal(SIGCHLD, handler);
  signal(SIGHUP, handler);
  signal(SIGTERM, handler);
  signal(SIGQUIT, handler);
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
          if (shell->param.cmd != NULL)
            shell->param.cmd[0] = '\0';
          shell->param.pos = 0;
          refresh_view(shell->param.cmd, &(shell->param));
          view(shell->param.cmd, &(shell->param));
        }
    }
  if (sig == SIGWINCH && shell->param.fallback == 1)
    clear_cmd(shell->param.cmd, &(shell->param));
  if ((sig == SIGHUP) || (sig == SIGTERM) || (sig == SIGQUIT))
    {
      SETFLAG(shell->beepbeepexit, FLAGPOS(EXIT_F_POS));
      close(0);
    }
  init_sig(&sig_handler);
}

void	call_signal_func(t_sh *shell, int chld_sig, t_cmd *chld_cmd)
{
  if ((chld_sig == SIGTSTP) || (chld_sig == SIGSTOP)
      || (chld_sig == SIGTTIN) || (chld_sig == SIGTTOU))
    {
      if (chld_cmd != NULL)
        {
          my_putstr(chld_cmd->line, 1, -1);
          my_putstr(" -> Stopped\n", 1, -1);
        }
      no_fg_jobs_status(shell);
    }
  wait_all_jobs(shell);
  rm_all_terminated_grp(shell);
  shell->signal = 0;
}
