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

int	builtins_print_echo(char *path, char **argv, t_sh *shell)
{
  int	i;
  int	first;

  i = 1;
  first = 1;
  while (argv[i] != NULL)
    {
      if (first == 0)
        my_putstr(" ", 1, -1);
      my_putstr(argv[i], 1, -1);
      first = 0;
      i++;
    }
  my_putstr("\n", 1, -1);
  my_exit(0);
  return (-1);
}

void	builtin_echo(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  exec_process(cmd, fd, shell, &builtins_print_echo);
}
