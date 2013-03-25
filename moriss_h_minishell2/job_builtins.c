/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	builtin_fg(t_prg *cmd, t_sh_info *shell)
{
  int	pgid;
  int	i;

  i = 0;
  if (cmd->argv[1] == NULL)
    {
      my_putstr("Please choose wich jobs\n", 2, -1);
      return ;
    }
  while ((shell->process_group[i] != NULL)
         && (i < my_getnbr(cmd->argv[1] - 1)))
    i++;
  if (shell->process_group[i] != NULL)
    {
      pgid = shell->process_group[i]->pgid;
      shell->forground = shell->process_group[i];
      shell->process_group[i]->running = 1;
      set_forground_pgrp(pgid);
      kill(-pgid, SIGCONT);
    }
}

void	builtin_bg(t_prg *cmd, t_sh_info *shell)
{
  int	pgid;
  int	i;

  i = 0;
  if (cmd->argv[1] == NULL)
    {
      my_putstr("Please choose wich jobs\n", 2, -1);
      return ;
    }
  while ((shell->process_group[i] != NULL)
         && (i < my_getnbr(cmd->argv[1] - 1)))
    i++;
  if (shell->process_group[i] != NULL)
    {
      pgid = shell->process_group[i]->pgid;
      shell->process_group[i]->running = 1;
      kill(-pgid, SIGTTIN);
      kill(-pgid, SIGCONT);
    }
}

void		builtin_jobs(t_prg *cmd, t_sh_info *shell)
{
  int		i;
  t_pipeline	*tmppipeline;
  char		*tmp;

  i = 0;
  if (shell->process_group != NULL)
    while ((tmppipeline = shell->process_group[i]) != NULL)
      {
        tmp = my_uint_strbase(i + 1, "0123456789");
        my_putstr("[", 1, -1);
        my_putstr(tmp, 1, -1);
        my_putstr("] ", 1, -1);
        my_putstr(tmppipeline->lign, 1, -1);
        my_putstr("\n", 1, -1);
        free(tmp);
        i++;
      }
}
