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

int	exec_a_pipe(t_sh *shell, t_grp *grp)
{
  t_fds	fd;
  int	ptab[2];
  t_cmd	*tmpcmd;
  int	i;

  i = 0;
  ptab[PIPE_READ] = -1;
  ptab[PIPE_WRITE] = -1;
  init_stdfd_t_def_val(&fd, grp->fd.stdin, grp->fd.stdout, grp->fd.stderr);
  if (grp->cmds == NULL)
    return (-1);
  while ((tmpcmd = grp->cmds[i]) != NULL)
    {
      if (grp->cmds[i + 1] != NULL)
        {
          if (pipe(ptab) == -1)
            return (-1);
          fd.stdout = ptab[PIPE_WRITE];
        }
      cmd_execution(tmpcmd, &fd, shell);
      init_stdfd_t_def_val(&fd, grp->fd.stdin, grp->fd.stdout, grp->fd.stderr);
      if (grp->cmds[i + 1] != NULL)
        fd.stdin = ptab[PIPE_READ];
      i++;
    }
  return (0);
}
