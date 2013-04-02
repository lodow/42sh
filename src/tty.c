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

void	set_forground_pgrp(pid_t pid)
{
  int	err;

  err = 0;
  if (pid != -1)
    {
      signal(SIGTTOU, SIG_IGN);
      if (isatty(0))
        err += tcsetpgrp(0, pid);
      if (isatty(1))
        err += tcsetpgrp(1, pid);
      if (isatty(2))
        err += tcsetpgrp(2, pid);
      if (err != 0)
        {
          my_putstr("Can't set tcsetpgrp, error: ", 2, -1);
          my_putstr(strerror(errno), 2, -1);
        }
      signal(SIGTTOU, SIG_DFL);
    }
}
