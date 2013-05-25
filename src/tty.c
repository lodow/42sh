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
