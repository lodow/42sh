/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Apr 15 20:49:31 2013 maxime lavandier
*/

#include "42sh.h"


int	builtin_echo_option(char **argv, int *new_line)
{
  int	i;

  i = 1;
  while (argv[i] != NULL && argv[i][0] == '-')
    {
      if (strcmp(argv[i], "-n") == 0)
	*new_line = 0;
      i++;
    }
  return (i);
}

int	builtins_print_echo(char *path, char **argv, t_sh *shell)
{
  int	i;
  int	first;
  int	new_line;

  first = 1;
  new_line = 1;
  i = builtin_echo_option(argv, &new_line);
  while (argv[i] != NULL)
    {
      if (first == 0)
        my_putstr(" ", 1, -1);
      my_putstr(argv[i], 1, -1);
      first = 0;
      i++;
    }
  if (new_line)
    my_putstr("\n", 1, -1);
  my_exit(0);
  return (-1);
}

void	builtin_echo(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  exec_process(cmd, fd, shell, &builtins_print_echo);
}
