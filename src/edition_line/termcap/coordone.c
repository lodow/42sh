/*
** coordone.c for coordone in /home/robert_r//my_select/direct
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 15 20:15:34 2013 remi robert
** Last update Sun Apr 14 16:10:44 2013 remi robert
*/

#include "my_func.h"

int			return_x(int tty)
{
  struct winsize	ws;

  ioctl(tty, TIOCGWINSZ, &ws);
  return (ws.ws_col);
}

int			return_y(int tty)
{
  struct winsize	ws;

  ioctl(tty, TIOCGWINSZ, &ws);
  return (ws.ws_row - 1);
}
