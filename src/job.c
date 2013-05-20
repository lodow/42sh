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

int	group_to_process_group(t_grp *grp, t_cmd *cmd)
{
  int	pgid;
  int	tmppid;

  if ((grp == NULL) || (cmd == NULL))
    return (-1);
  if (cmd->pid.pid == -1)
    return (0);
  if ((pgid = grp->pid.pgid) == -1)
    {
      if ((pgid = cmd->pid.pid) != -1)
        if (check_perror("Setpgid", setpgid(pgid, pgid)) == -1)
          return (-1);
      grp->pid.pgid = pgid;
    }
  else
    {
      if ((tmppid = cmd->pid.pid) != -1)
        if (check_perror("Setpgid", setpgid(tmppid, pgid)) == -1)
          return (-1);
    }
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
