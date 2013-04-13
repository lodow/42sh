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

void	parse_user_cmd(t_sh *shell, char *line)
{
  t_grp	*grp;
  char	**tmptab;
  char	*tmpline;
  int	i;

  i = 0;
  if ((tmptab = str_to_wordtab(line, ";", 1)) != NULL)
    while ((tmpline = tmptab[i]) != NULL)
      {
        wait_no_fg_grp(shell);
        grp = create_n_process_group(shell, my_strdup(tmpline));
        ///Launch option flag are set here
        SETFLAG(grp->flags, FLAGPOS(FGRP_FORGROUND));
        exec_process_group(shell, grp);
        i++;
      }
  free_ptr_tab((void**)tmptab);
}
