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

void	parse_user_cmd(t_sh *shell, char *line)
{
  t_grp	*grp;

  grp = create_n_process_group(shell, my_strdup(line));
  ///Launch option flag are set here
  SETFLAG(grp->flags, FLAGPOS(FGRP_FORGROUND));
  exec_process_group(shell, grp);

}
