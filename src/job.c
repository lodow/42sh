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

int	exec_grp_lst(t_grp **grp_lst, t_sh *shell)
{
  int	i;
  int	exec;
  t_grp	*tmpgrp;

  i = 0;
  if ((grp_lst == NULL) || (shell == NULL))
    return (-1);
  while ((tmpgrp = grp_lst[i]) != NULL)
    {
      exec = exec_process_group(shell, tmpgrp);
      if (MEXIT)
        return (0);
      if (exec == -1)
        free_process_group(tmpgrp);
      else
        wait_no_fg_grp(shell);
      i++;
    }
  return (0);
}

int	group_to_process_group(t_grp *grp, t_cmd *cmd)
{
  int	i;
  t_cmd	*tmpcmd;

  i = 0;
  if ((cmd != NULL) && (grp != NULL)
      && (cmd->pid.pid != -1) && (cmd->pid.pgid == -1))
    {
      while ((tmpcmd = grp->cmds[i]) != NULL)
        {
          tmpcmd->pid.pgid = cmd->pid.pid;
          i++;
        }
      grp->pid.pgid = cmd->pid.pgid;
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
