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
          my_putstr(": command not found\n", 2, -1);
          return (0);
        }
      i++;
    }
  return (1);
}
