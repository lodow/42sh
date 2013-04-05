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

int	exec_process_group(t_sh *shell, t_grp *grp)
{
  if (grp == NULL)
    return (-1);
  if (is_grp_exec(grp) == 0)
    return (-1);
  exec_a_pipe(shell, grp);
  group_process_group(grp);
  shell->process_group = (t_grp**)add_ptr_t_tab((void**)shell->process_group,
                         (void*)grp);
  SETFLAG(grp->flags, FLAGPOS(FGRP_RUNNING));
  if (GETFLAG(grp->flags, FLAGPOS(FGRP_FORGROUND)))
    set_forground_process_g(shell, grp);
  return (0);
}

t_grp	*create_n_process_group(t_sh *shell, char *lign)
{
  char	**cmd_line;
  t_grp	*res;
  t_cmd	*tmp_cmd;
  int	i;

  i = 0;
  if ((res = malloc(1 * sizeof(t_grp))) == NULL)
    return (NULL);
  res->line = lign;
  init_stdfd_t_def_val(&(res->fd), 0, 1, 2);
  res->pid.sid = shell->pid.sid;
  res->cmds = NULL;
  res->flags = 0;
  cmd_line = str_to_wordtab(lign, "|", 1);
  while ((cmd_line != NULL) && (cmd_line[i] != NULL))
    {
      tmp_cmd = create_n_cmd(shell, cmd_line[i]);
      res->cmds = (t_cmd**)add_ptr_t_tab((void**)res->cmds, (void*)tmp_cmd);
      i++;
    }
  ///check here for redirection
  free(cmd_line);
  return (res);
}

void	free_process_group(t_grp *grp)
{
  if (grp != NULL)
    {
      free(grp->line);
      free_ptr_tab((void**)grp->cmds);
    }
}
