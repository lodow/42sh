/*
** coordone.c for coordone in /home/robert_r//my_select/direct
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 15 20:15:34 2013 remi robert
** Last update Mon Apr 29 09:05:51 2013 remi robert
*/

#include "termcap.h"

int			return_x(void)
{
  struct winsize	ws;

  if (ioctl(1, TIOCGWINSZ, &ws) == -1)
    return (0);
  return (ws.ws_col);
}

int			return_y(void)
{
  struct winsize	ws;

  if (ioctl(1, TIOCGWINSZ, &ws) == -1)
    return (0);
  return (ws.ws_row - 1);
}
