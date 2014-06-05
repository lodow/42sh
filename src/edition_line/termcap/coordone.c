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
