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

  if ((grp == NULL) || (grp->transition == GRP_TRANS_NONE))
    return (0);
  fdout = grp->fd.stdout;
  gobst = global_group_ret_status(grp);
  if (((grp->transition == GRP_TRANS_AND) && (gobst == 0))
      || ((grp->transition == GRP_TRANS_OR) && (gobst != 0)))
    {
      parse_user_cmd(shell, grp->transition_line, fdout);
      grp->transition = GRP_TRANS_NONE;
      ///set last grp to same flag
      return (1);
    }
  return (0);
}

char	*type_next_and_or(char *line, int *type)
{
  char	**taba;
  char	**tabo;
  char	*next_line;

  taba = str_to_wordtab(line, "&&", 1);
  tabo = str_to_wordtab(line, "||", 1);
  *type = GRP_TRANS_NONE;
  next_line = NULL;
  if (my_strlen(taba[0]) < my_strlen(tabo[0]))
    {
      *type = GRP_TRANS_AND;
      next_line = my_strdup(&(line[2 + my_strlen(taba[0])]));
      line[my_strlen(taba[0])] = '\0';
    }
  else if (my_strlen(taba[0]) > my_strlen(tabo[0]))
    {
      *type = GRP_TRANS_OR;
      next_line = my_strdup(&(line[2 + my_strlen(tabo[0])]));
      line[my_strlen(tabo[0])] = '\0';
    }
  free_ptr_tab((void**)taba);
  free_ptr_tab((void**)tabo);
  return (next_line);
}
