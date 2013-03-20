/*
** coordone.c for coordone in /home/robert_r//my_select/direct
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 15 20:15:34 2013 remi robert
** Last update Wed Mar 20 14:28:02 2013 remi
*/

#include "../my_func.h"

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
