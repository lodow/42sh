#include "42sh.h"

void	builtin_bg(t_cmd *cmd, UNSEDP t_fds *fd, t_sh *shell)
{
  int	pgid;
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  if (shell->process_group == NULL)
    return ;
  if (cmd->argv[1] != NULL)
    nb =  my_getnbr(cmd->argv[1]) - 1;
  while ((shell->process_group[i] != NULL) && (i < nb))
    i++;
  if (shell->process_group[i] != NULL)
    {
      pgid = shell->process_group[i]->pid.pgid;
      SETFLAG(shell->process_group[i]->flags, FLAGPOS(FGRP_RUNNING));
      kill(-pgid, SIGCONT);
    }
}
