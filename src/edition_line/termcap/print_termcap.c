/*
** print_termcap.c for print_termcap in /home/remi/42sh/edition_line2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue May 14 16:31:54 2013 remi robert
** Last update Mon May 20 15:04:14 2013 remi robert
*/

#include "42sh.h"

int		my_putstr_termcap(int flag, char *capaity)
{
  static int	fd = -1;
  int		indice;

  if (flag == CLOSE_FD_TTY)
    {
      if (close(fd) == -1)
	my_perror("close");
      return (-1);
    }
  if (flag != -1)
    fd = flag;
  if (flag == -1 && fd == -1)
    if ((fd = open("/dev/tty", O_RDWR)) == -1)
      my_perror("open");
  if (fd != -1 && capaity != NULL)
    {
      indice = -1;
      while (capaity[++indice] != '\0');
      if (write(fd, capaity, indice) == -1)
	write(2, "Error write capacity termcap\n", 30);
    }
  return (fd);
}
