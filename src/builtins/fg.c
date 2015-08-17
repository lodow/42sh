#include "42sh.h"

void	builtin_fg(t_cmd *cmd, UNSEDP t_fds *fd, t_sh *shell)
{
  int	pgid;
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  if (shell->process_group == NULL || !shell->jobcontrol)
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
