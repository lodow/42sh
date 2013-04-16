/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Apr 16 15:27:34 2013 maxime lavandier
*/

#include "42sh.h"

void	builtin_clear(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  char	*str;

  str  = tgetstr("cl", 0);
  if (str == NULL)
    {
      write(2, "Clear error\n", 12);
      return ;
    }
  write(1, str, strlen(str));
}

