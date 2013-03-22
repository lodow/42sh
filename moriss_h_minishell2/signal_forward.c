/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"include.h"

void	handle_signal(int sig)
{
  if (sig == SIGTSTP)
    set_forground_pgrp(getpgid(getpid()));
  signal(SIGTTOU, &handle_signal);
  signal(SIGTTIN, &handle_signal);
  signal(SIGINT, &handle_signal);
  signal(SIGTSTP, &handle_signal);
}
