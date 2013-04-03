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

int	group_process_group(t_grp *pipeline)
{
  int	i;
  int	pgid;
  int	tmppid;

  i = 1;
  pipeline->pid.pgid = -1;
  if ((pipeline->cmds != NULL) && (pipeline->cmds[0] != NULL))
    {
      pgid = pipeline->cmds[0]->pid.pid;
      if (setpgid(pgid, pgid) == -1)
        return (-1);
    }
  else
    return (0);
  while (pipeline->cmds[i] != NULL)
    {
      tmppid = pipeline->cmds[i]->pid.pid;
      if (setpgid(tmppid, pgid) == -1)
        return (-1);
      i++;
    }
  pipeline->pid.pgid = pgid;
  return (0);
}

void	update_jobs_status(t_sh *shell, int sig)
{
  if ((sig == SIGTSTP) && (shell->forground != NULL))
    {
      shell->forground->running = 0;
      shell->forground = NULL;
    }
}
