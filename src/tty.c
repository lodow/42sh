#include "42sh.h"

int launch_tmp_son()
{
  int spid;

  spid = fork();
  if (spid == 0)
  {
  	usleep(2000);
	exit(0);
  }
  else if (spid == -1)
  {
  	return (-1);
  }
  return (spid);
}

void	try_job_control(t_sh *sh)
{
  int 	err;
  int   spid;

  spid = launch_tmp_son();
  signal(SIGTTOU, SIG_IGN);
  signal(SIGTTIN, SIG_IGN);
  sh->jobcontrol = 1;
  err = tcsetpgrp(0, getpgid(spid));
  if (err < 0)
  {
  	waitpid(spid, &err, 0);
	err = setsid();
	spid = launch_tmp_son();
	if (err < 0)
	{
	  my_putstr("setsid successful\n", 1, -1);
	  err = tcsetpgrp(0, getpgid(spid));
	  if (err < 0)
	    sh->jobcontrol = 0;
	}
  }
  waitpid(spid, &err, 0);
  tcsetpgrp(0, getpgid(0));
  signal(SIGTTOU, SIG_DFL);
  signal(SIGTTIN, SIG_DFL);
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
//      if (err != 0)
//        my_perror("Can't set tcsetpgrp");
      signal(SIGTTOU, SIG_DFL);
      signal(SIGTTIN, SIG_DFL);
    }
  return (err);
}
