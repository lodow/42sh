/*
** coordone.c for coordone in /home/robert_r//my_select/direct
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 15 20:15:34 2013 remi robert
** Last update Tue Apr  9 16:30:27 2013 remi robert
*/

#include "../../../include/my_func.h"

int			return_x()
{
  struct winsize	ws;

  ioctl(1, TIOCGWINSZ, &ws);
  return (ws.ws_col);
}

int			return_y()
{
  struct winsize	ws;

  ioctl(1, TIOCGWINSZ, &ws);
  return (ws.ws_row - 1);
}
