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

void	change_fdout_t_def_z(t_grp *grp, int def_fdout)
{
  if (grp != NULL)
    if (grp->fd.stdout == 1)
      grp->fd.stdout = def_fdout;
}

void	parse_grp(t_sh *shell, char *line, int def_fdout, int back)
{
  t_grp	*grp;

  grp = create_n_process_group(shell, my_strdup(line));
  change_fdout_t_def_z(grp, def_fdout);
  if (back == 0)
    SETFLAG(grp->flags, FLAGPOS(FGRP_FORGROUND));
  exec_process_group(shell, grp);
}

void	parse_linked_grp_process(t_sh *shell, char *line, int def_fdout, int back)
{
  parse_grp(shell, line, def_fdout, back);
  if (MEXIT)
    return ;
}

int	launch_background(char **line)
{
  int	back;
  int	i;
  char	**tab;

  back = 0;
  i = 0;
  tab = str_to_wordtab((*line), " ", 1);
  if (tab != NULL)
    {
      while (tab[i] != NULL)
        i++;
      if (i > 0)
        if (!(my_strncmp(tab[i - 1], "&", -1)))
          {
            back = 1;
            free(tab[i - 1]);
            tab[i - 1] = NULL;
          }
      // free((*line));
      (*line) = tab_file_tstr(tab, ' ');
    }
  return (back);
}

void	parse_user_cmd(t_sh *shell, char *line, int def_fdout)
{
  char	**tmptab;
  char	*tmpline;
  int	i;
  int	back;

  i = 0;
  back = launch_background(&line);
  line = check_and_load_backquote(line, shell);
  if (MEXIT)
    return ;
  if ((tmptab = str_to_wordtab(line, ";", 1)) != NULL)
    while ((tmpline = tmptab[i]) != NULL)
      {
        parse_linked_grp_process(shell, tmpline, def_fdout, back);
        if (MEXIT)
          return ;
        i++;
      }
  if (back == 1)
    no_fg_jobs_status(shell);
  free_ptr_tab((void**)tmptab);
  free(line);
}
