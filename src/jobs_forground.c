#include "42sh.h"

t_grp	*get_forground_grp(t_sh *shell)
{
  int	i;
  t_grp	**pr_grp;
  t_grp	*tmp_grp;

  i = 0;
  pr_grp = shell->process_group;
  if (pr_grp == NULL)
    return (NULL);
  while ((tmp_grp = pr_grp[i]) != NULL)
    {
      if (GETFLAG(tmp_grp->flags, FLAGPOS(FGRP_FORGROUND))
          && !GETFLAG(tmp_grp->flags, FLAGPOS(FGRP_TERMINATED)))
        return (tmp_grp);
      i++;
    }
  return (NULL);
}

void	set_forground_process_g(t_sh *shell, t_grp *grp)
{
  int	i;
  t_grp	*tmp_grp;

  i = 0;
  if (shell->process_group == NULL || !shell->jobcontrol)
    return ;
  while ((tmp_grp = shell->process_group[i]) != NULL)
    {
      if (tmp_grp == grp)
        {
          SETFLAG(tmp_grp->flags, FLAGPOS(FGRP_FORGROUND));
          if (set_forground_pgrp(grp->pid.pgid) == -1)
            set_forground_pgrp(shell->pid.pgid);
        }
      else
        UNSETFLAG(tmp_grp->flags, FLAGPOS(FGRP_FORGROUND));
      i++;
    }
}
