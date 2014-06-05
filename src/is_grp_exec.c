#include "42sh.h"

int	is_cmd_executable(t_cmd *cmd)
{
  if ((cmd->argv == NULL) || (cmd->argv[0] == NULL)
      || (cmd->argv[0][0] == '\0') || (cmd->cmd_fpath == NULL)
      || (access(cmd->cmd_fpath, F_OK) == -1)
      || (access(cmd->cmd_fpath, X_OK) == -1))
    return (0);
  return (1);
}

int	is_grp_exec(t_sh *shell, t_grp *grp)
{
  int	i;
  t_cmd	*tmpcmd;

  i = 0;
  if ((grp == NULL) || (grp->cmds == NULL))
    return (0);
  while ((tmpcmd = grp->cmds[i]) != NULL)
    {
      if ((is_cmd_executable(tmpcmd) == 0)
          && (is_cmd_a_builtin(tmpcmd, NULL, shell, 0) == 0))
        {
          if (tmpcmd->argv != NULL)
            my_putstr(tmpcmd->argv[0], 2, -1);
          tmpcmd->return_value = 1;
          my_putstr(": command not found\n", 2, -1);
          return (0);
        }
      i++;
    }
  return (1);
}

void	rm_all_terminated_grp(t_sh *shell)
{
  int	i;
  t_grp	*grp;

  i = 0;
  if (shell != NULL)
    while ((shell->process_group != NULL)
           && (grp = shell->process_group[i]) != NULL)
      {
        if (GETFLAG(grp->flags, FLAGPOS(FGRP_TERMINATED)))
          {
            i = 0;
            free_process_group(grp);
            rm_ptr_f_tab((void**)shell->process_group, (void*)grp);
          }
        i++;
      }
}
