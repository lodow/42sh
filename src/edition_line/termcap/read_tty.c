/*
** read_tty.c for read_tty in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr 29 10:22:43 2013 remi robert
** Last update Tue May 14 20:52:33 2013 remi robert
*/

#include "42sh.h"

int	open_tty(void)
{
  int	fd;

  fd = open(TTY_OPEN, O_RDWR);
  if (fd == -1)
    return (FAIL_OPEN);
  return (fd);
}
