/*
** read_tty.c for read_tty in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr 29 10:22:43 2013 remi robert
** Last update Mon May 20 15:01:51 2013 remi robert
*/

#include "42sh.h"

int	open_tty(void)
{
  int	fd;

  fd = open("/dev/tty", O_RDWR);
  if (fd == -1)
    {
      my_perror("open");
      return (-1);
    }
  return (fd);
}
