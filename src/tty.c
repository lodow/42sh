#include "42sh.h"

int	set_forground_pgrp(pid_t pgid)
{
  int	err;

  err = 0;
  if (pgid != -1)
    {
      signal(SIGTTOU, SIG_IGN);
      signal(SIGTTIN, SIG_IGN);
      if (isatty(0))
        err += tcsetpgrp(0, pgid);
      if (isatty(1))
        err += tcsetpgrp(1, pgid);
      if (isatty(2))
        err += tcsetpgrp(2, pgid);
      if (err != 0)
        my_perror("Can't set tcsetpgrp");
      signal(SIGTTOU, SIG_DFL);
      signal(SIGTTIN, SIG_DFL);
    }
  return (err);
}
