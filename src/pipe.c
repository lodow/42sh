#include "42sh.h"

int	create_pipe(t_grp *grp, int ptab[2], t_fds *fd, int i)
{
  if (grp->cmds[i + 1] != NULL)
    {
      if (pipe(ptab) == -1)
        {
          my_perror("Pipe");
          return (-1);
        }
      fd->stdout = ptab[PIPE_WRITE];
    }
  return (0);
}

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
      if (create_pipe(grp, ptab, &fd, i) == -1)
        return (-1);
      cmd_execution(tmpcmd, &fd, shell);
      if (MEXIT)
        return (0);
      group_to_process_group(grp, tmpcmd);
      init_stdfd_t_def_val(&fd, grp->fd.stdin, grp->fd.stdout, grp->fd.stderr);
      if (grp->cmds[i + 1] != NULL)
        fd.stdin = ptab[PIPE_READ];
      i++;
    }
  return (0);
}
