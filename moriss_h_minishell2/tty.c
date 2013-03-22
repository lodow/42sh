/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	set_forground_pgrp(pid_t pid)
{
  if (isatty(0))
    tcsetpgrp(0, pid);
  if (isatty(1))
    tcsetpgrp(1, pid);
  if (isatty(2))
    tcsetpgrp(2, pid);
}