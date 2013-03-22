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

int	group_pipeline_process(t_pipeline *pipeline)
{
  int	i;
  int	pgid;
  int	tmppid;

  i = 1;
  pipeline->pgid = -1;
  if (pipeline->nb > 0)
    {
      pgid = pipeline->prg_list[0]->pidf;
      if (setpgid(pgid, pgid) == -1)
        return (-1);
    }
  while (i < pipeline->nb)
    {
      tmppid = pipeline->prg_list[i]->pidf;
      if (setpgid(tmppid, pgid) == -1)
        return (-1);
      i++;
    }
  pipeline->pgid = pgid;
  return (0);
}

int		check_terminated_jobs(t_sh_info *shell)
{
  int		i;
  int		j;
  int		done;
  int		prompt;
  t_pipeline	*tmppipeline;

  i = 0;
  prompt = 1;
  if (shell->process_group == NULL)
    return (1);
  while ((tmppipeline = shell->process_group[i]) != NULL)
    {
      j = 0;
      done = 0;
      while (j < tmppipeline->nb)
        {
          done += (tmppipeline->prg_list[j]->done - 1);
          j++;
        }
      if (done == 0)
        {
          rm_pipeline(tmppipeline);
          rm_ptr_f_tab((void**)shell->process_group, tmppipeline);
        }
      else if (tmppipeline->forground == 1)
        prompt = 0;
      i++;
    }
  return (prompt);
}
