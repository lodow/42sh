/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "../../include/42sh.h"

void	builtin_fg(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  int	pgid;
  int	i;

  i = 0;
  if (cmd->argv[1] == NULL)
    {
      my_putstr("Please choose wich jobs\n", 2, -1);
      return ;
    }
  while ((shell->process_group[i] != NULL)
         && (i < my_getnbr(cmd->argv[1]) - 1))
    i++;
  if (shell->process_group[i] != NULL)
    {
      pgid = shell->process_group[i]->pid.pgid;
      if (pgid != -1)
        {
          SETFLAG(shell->process_group[i]->flags, FLAGPOS(FGRP_FORGROUND));
          SETFLAG(shell->process_group[i]->flags, FLAGPOS(FGRP_RUNNING));
          //setpgid(shell->pid.pgid, shell->process_group[i]->pid.pgid);
          set_forground_pgrp(pgid);
          kill(-pgid, SIGCONT);
        }
    }
}
