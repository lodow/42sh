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

void	exec_next_i_fail(t_sh *shell, char *line, int back)
{
  t_grp	*tmpgrp;
  t_fds	fd;

  line = my_strdup(line);
  init_stdfd_t_def_val(&fd, 0, 1, 2);
  if ((tmpgrp = parse_linked_grp_process(shell, line, &fd, back)) != NULL)
    exec_next_grp(tmpgrp, shell);
  free_process_group(tmpgrp);
}

int	exec_next_grp(t_grp *grp, t_sh *shell)
{
  t_fds	fd;
  int	gobst;
  char	*line;
  char	*tmp;
  int	back;

  if ((grp == NULL) || (grp->transition == GRP_TRANS_NONE))
    return (0);
  init_stdfd_t_def_val(&fd, 0, 1, 2);
  gobst = global_group_ret_status(grp);
  line = my_strdup(grp->transition_line);
  tmp = line;
  back = GETFLAG(grp->flags, FLAGPOS(FGRP_RUNNING));
  if (((grp->transition == GRP_TRANS_AND) && (gobst == 0))
      || ((grp->transition == GRP_TRANS_OR) && (gobst != 0)))
    {
      parse_user_cmd(shell, &line, &fd);
      if (line != tmp)
        free(line);
      return (1);
    }
  exec_next_i_fail(shell, line, back);
  free(line);
  return (0);
}

char	*type_next_and_or(char *line, int *type)
{
  char	*sepa[3];
  char	**tab;
  char	*next_line;

  sepa[0] = "&&";
  sepa[1] = "||";
  sepa[2] = NULL;
  tab = mult_str_to_wordtab(line, sepa, 1);
  *type = GRP_TRANS_NONE;
  next_line = NULL;
  if (!my_strncmp(get_inibiteur_f_mult_wt(line, sepa, tab, 0), "&&", -1))
    {
      *type = GRP_TRANS_AND;
      next_line = my_strdup(&(line[2 + my_strlen(tab[0])]));
      line[my_strlen(tab[0])] = '\0';
    }
  else if (!my_strncmp(get_inibiteur_f_mult_wt(line, sepa, tab, 0), "||", -1))
    {
      *type = GRP_TRANS_OR;
      next_line = my_strdup(&(line[2 + my_strlen(tab[0])]));
      line[my_strlen(tab[0])] = '\0';
    }
  free_ptr_tab((void**)tab, &free);
  return (next_line);
}
