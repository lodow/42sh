/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "42sh.h"

void	store_history_f(t_sh *shell, int fd)
{
  t_history	*tmp;

  tmp = shell->history;
  while (tmp != NULL)
    {
      my_putstr(tmp->cmd, fd, -1);
      my_putstr("\n", fd, -1);
      tmp = tmp->next;
    }
}

void	store_conf_file(const char *filename, t_sh *shell,
                      void (*f)(t_sh *shell, int fd))
{
  int	fd;

  if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, REDI_FRIGHT)) == -1)
    {
      my_putstr("Can't open config file: ", 2, -1);
      my_putstr(filename, 2, -1);
      my_putstr("\n", 2, -1);
      return ;
    }
  f(shell, fd);
  close(fd);
}
