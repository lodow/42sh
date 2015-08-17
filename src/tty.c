#include "42sh.h"

void	try_job_control(t_sh *sh)
{
  int 	err;

   sh->jobcontrol = 1;
  err = tcsetpgrp(0, getpgid(0));
  if (err < 0)
  {
	err = setsid();
	if (err < 0)
	{
	  err = tcsetpgrp(0, getpgid(0));
	  if (err < 0)
	    sh->jobcontrol = 0;
	}
  }
  if (sh->jobcontrol == 0)
    my_perror("Job control won't be available for this session");
}

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
