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

void	builtin_fg(t_cmd *cmd, UNSEDP t_fds *fd, t_sh *shell)
{
  int	pgid;
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  if (shell->process_group == NULL)
    return ;
  if (cmd->argv[1] != NULL)
    nb = my_getnbr(cmd->argv[1]) - 1;
  while ((shell->process_group[i] != NULL) && (i < nb))
    i++;
  if (shell->process_group[i] != NULL)
    {
      pgid = shell->process_group[i]->pid.pgid;
      if (pgid != -1)
        {
          SETFLAG(shell->process_group[i]->flags, FLAGPOS(FGRP_FORGROUND));
          SETFLAG(shell->process_group[i]->flags, FLAGPOS(FGRP_RUNNING));
          if (set_forground_pgrp(pgid) == -1)
            set_forground_pgrp(shell->pid.pgid);
          kill(-pgid, SIGCONT);
        }
    }
}
