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

void	set_forground_pgrp(pid_t pgid)
{
  int	err;

  err = 0;
  if (pgid != -1)
    {
      signal(SIGTTOU, SIG_IGN); //Find why we ahve todo that !
      if (isatty(0))
        err += tcsetpgrp(0, pgid);
      if (isatty(1))
        err += tcsetpgrp(1, pgid);
      if (isatty(2))
        err += tcsetpgrp(2, pgid);
      if (err != 0)
        {
          my_putstr("Can't set tcsetpgrp, error: ", 2, -1);
          my_putstr(strerror(errno), 2, -1);
        }
      signal(SIGTTOU, SIG_DFL);
    }
}

void	set_forground_process_g(t_sh *shell, t_grp *grp)
{
  shell->process_group = (t_grp**)add_ptr_t_tab((void**)shell->process_group,
                                       (void*)grp);
  shell->forground = grp;
  grp->running = 1;
  set_forground_pgrp(grp->pid.pgid);
}
