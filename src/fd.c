#include "42sh.h"

void	change_fdout_t_def_z(t_grp *grp, t_fds *def_fd)
{
  if (grp != NULL)
    {
      if ((grp->fd.stdout == 0) && (isatty(def_fd->stdin) != -1))
        grp->fd.stdin = def_fd->stdin;
      if ((grp->fd.stdout == 1) && (isatty(def_fd->stdout) != -1))
        grp->fd.stdout = def_fd->stdout;
      if ((grp->fd.stdout == 2) && (isatty(def_fd->stderr) != -1))
        grp->fd.stderr = def_fd->stderr;
    }
}

void	init_stdfd_t_def_val(t_fds *fds, int stdin, int stdout, int stderr)
{
  fds->stdin = 0;
  fds->stdout = 1;
  fds->stderr = 2;
  if ((stdin != -1) && (isatty(stdin) != -1))
    fds->stdin = stdin;
  if ((stdout != -1) && (isatty(stderr) != -1))
    fds->stdout = stdout;
  if ((stderr != -1) && (isatty(stdout) != -1))
    fds->stderr = stderr;
}

int	safe_close(int fd)
{
  if (fd > 2)
    return (check_perror("Close", close(fd)));
  return (1);
}

void	close_fds(t_fds *fd)
{
  safe_close(fd->stdin);
  safe_close(fd->stdout);
  safe_close(fd->stderr);
}
