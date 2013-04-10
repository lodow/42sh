/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Apr 10 13:47:16 2013 remi robert
*/

#include "../include/42sh.h"

/*
** Func that execute a group of command,
** It return -1 if not executable or if it has failed
*/
int	exec_process_group(t_sh *shell, t_grp *grp)
{
  if (grp == NULL)
    return (-1);
  if (is_grp_exec(shell, grp) == 0)
    return (-1);
  /* creer fichier */
  rempl_fd_process(grp->redirection, grp);
  exec_a_pipe(shell, grp);
  if (group_process_group(grp) == -1)
    return (-1);
  shell->process_group = (t_grp**)add_ptr_t_tab((void**)shell->process_group,
                         (void*)grp);
  if (GETFLAG(grp->flags, FLAGPOS(FGRP_FORGROUND)) && (grp->pid.pgid != -1))
    set_forground_process_g(shell, grp);
  else
    UNSETFLAG(grp->flags, FLAGPOS(FGRP_FORGROUND));
  return (0);
}

void	detect_redirection(t_redirection *red, char *str)
{
  red->red_g = 0;
  red->red_b = 0;
  red->file_g = NULL;
  red->file_b = NULL;
  return_type_redirection(str, &(red->red_b), &(red->red_g));
  if (red->red_g != 0)
    red->file_g = find_name_redirection(red->red_g, str);
  if (red->red_b != 0)
    red->file_b = find_name_redirection(red->red_b, str);
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
  detect_redirection(&(res->redirection), lign);
  cmd_line = str_to_wordtab(lign, "|", 1);
  while ((cmd_line != NULL) && (cmd_line[i] != NULL))
    {
      tmp_cmd = create_n_cmd(shell, cmd_line[i]);
      res->cmds = (t_cmd**)add_ptr_t_tab((void**)res->cmds, (void*)tmp_cmd);
      i++;
    }
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
