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

int	exec_next_grp(t_grp *grp, t_sh *shell)
{
  int	fdout;
  int	gobst;
  int	flags;
  t_grp	*this_grp;
  int	size;

  if ((grp == NULL) || (grp->transition == GRP_TRANS_NONE))
    return (0);
  flags = grp->flags;
  fdout = grp->fd.stdout;
  gobst = global_group_ret_status(grp);
  if (((grp->transition == GRP_TRANS_AND) && (gobst == 0))
      || ((grp->transition == GRP_TRANS_OR) && (gobst != 0)))
    {
      parse_user_cmd(shell, grp->transition_line, fdout);
      grp->transition = GRP_TRANS_NONE;
      size = ptr_tab_size((void**)(shell->process_group)) - 1;
      if (size >= 0)
        {
          this_grp = shell->process_group[size];
          this_grp->flags = flags;
        }
      return (1);
    }
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
