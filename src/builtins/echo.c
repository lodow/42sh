/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Apr 15 21:59:40 2013 maxime lavandier
*/

#include "42sh.h"

void	builtin_echo_putstr(char *str)
{
  int	i;
  char	temp;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\\')
	{
	  temp = ECHO_1(str[i + 1]);
	  if (temp == -1)
	    my_putchar('\\');
	  else
	    {
	      if (temp != -2)
		my_putchar(temp);
	      i++;
	    }
	}
      else
	my_putstr(&(str[i]), 1, 1);
      i++;
    }
}

int	builtin_echo_option(char **argv, int *new_line, int *interpret)
{
  int	i;

  i = 1;
  while (argv[i] != NULL && argv[i][0] == '-')
    {
      if (my_strncmp(argv[i], "-n", -1) == 0)
	*new_line = 0;
      else if (my_strncmp(argv[i], "-e", -1) == 0)
	*interpret = 1;
      else if (my_strncmp(argv[i], "-E", -1) == 0)
	*interpret = 0;
      else
	return (i);
      i++;
    }
  return (i);
}

int	builtins_print_echo(char *path, char **argv, t_sh *shell)
{
  int	i;
  int	first;
  int	new_line;
  int	interpret;

  first = 1;
  new_line = 1;
  interpret = 0;
  i = builtin_echo_option(argv, &new_line, &interpret);
  while (argv[i] != NULL)
    {
      if (first == 0)
        my_putstr(" ", 1, -1);
      if (!interpret)
	my_putstr(argv[i], 1, -1);
      else
	builtin_echo_putstr(argv[i]);
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
