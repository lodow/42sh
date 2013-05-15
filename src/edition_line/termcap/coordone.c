/*
** coordone.c for coordone in /home/robert_r//my_select/direct
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 15 20:15:34 2013 remi robert
** Last update Tue May 14 20:52:14 2013 remi robert
*/

#include "42sh.h"

int			return_x(void)
{
  struct winsize	ws;
  int			fd;

  fd = my_putstr_termcap(-1, NULL);
  if (ioctl(fd, TIOCGWINSZ, &ws) == -1)
    return (0);
  return (ws.ws_col);
}

int			return_y(void)
{
  struct winsize	ws;
  int			fd;

  fd = my_putstr_termcap(-1, NULL);
  if (ioctl(fd, TIOCGWINSZ, &ws) == -1)
    return (0);
  return (ws.ws_row - 1);
}
