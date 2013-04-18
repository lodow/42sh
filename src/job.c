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

int	group_process_group(t_grp *pipeline)
{
  int	i;
  int	pgid;
  int	tmppid;

  i = 1;
  pipeline->pid.pgid = -1;
  if ((pipeline->cmds != NULL) && (pipeline->cmds[0] != NULL))
    {
      if ((pgid = pipeline->cmds[0]->pid.pid) != -1)
        if (setpgid(pgid, pgid) == -1)
          return (-1);
    }
  else
    return (0);
  while (pipeline->cmds[i] != NULL)
    {
      if (((tmppid = pipeline->cmds[i]->pid.pid) != -1) && (pgid != -1))
        if (setpgid(tmppid, pgid) == -1)
          return (-1);
      i++;
    }
  pipeline->pid.pgid = pgid;
  return (0);
}

void	no_fg_jobs_status(t_sh *shell)
{
  t_grp	*fg_grp;

  if ((fg_grp = get_forground_grp(shell)) != NULL)
    {
      UNSETFLAG(fg_grp->flags, FLAGPOS(FGRP_RUNNING));
      UNSETFLAG(fg_grp->flags, FLAGPOS(FGRP_FORGROUND));
      set_forground_pgrp(shell->pid.pgid);
    }
}
