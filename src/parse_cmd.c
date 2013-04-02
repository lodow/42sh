/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "../include/42sh.h"

int	exec_process_group(t_pipe *grp)
{
  return (-1);
}

void	parse_user_cmd(t_sh *shell, char *line)
{
  t_pipe	*grp;

  grp = create_n_process_group(shell, line);
  exec_process_group(grp);
}
