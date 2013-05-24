/*
** coordone.c for coordone in /home/robert_r//my_select/direct
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 15 20:15:34 2013 remi robert
** Last update Fri May 24 20:43:42 2013 maxime lavandier
*/

#include "42sh.h"

int			return_x(void)
{
  struct winsize	ws;
  int			fd;

  fd = my_putstr_termcap(-1, NULL);
  if (ioctl(fd, TIOCGWINSZ, &ws) == -1)
    {
      my_perror("ioctl");
      return (1);
    }
  return (ws.ws_col);
}

int			return_y(void)
{
  struct winsize	ws;
  int			fd;

  fd = my_putstr_termcap(-1, NULL);
  if (ioctl(fd, TIOCGWINSZ, &ws) == -1)
    {
      my_perror("ioctl");
      return (1);
    }
  return (ws.ws_row - 1);
}
