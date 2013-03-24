/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Dec 12 17:50:32 2012 Hugues
*/

#include "include.h"

void	print_prompt(t_sh_info *shell)
{
  char	*prompt;
  char	*ps1;

  if ((ps1 = get_envvar("PS1", shell->envp)) != NULL)
    {
      if ((prompt = check_vars_in_str(ps1, shell->envp)) != NULL)
        {
          my_putstr(prompt, 1, -1);
          free(prompt);
        }
      else
        my_putstr(ps1, 1, -1);
    }
  else
    my_putstr("$ ", 1, -1);
}

t_pipeline	*pipeline_cced(char *lign, t_sh_info *shell)
{
  t_pipeline	*pipeline;

  pipeline = lign_into_pipeligne(lign, shell);
  pipeline->lign = lign;
  if ((pipeline != NULL) && (is_pipeline_exec_a(pipeline) != 0))
    {
      check_and_set_redirection(pipeline);
      if (pipe_exec_pipeline(pipeline, shell) != -1)
        {
          group_pipeline_process(pipeline);
          setpgid(shell->sh_pid, pipeline->pgid);
          set_forground_pgrp(pipeline->pgid);
          if (pipeline->drd != -1)
            cat_t_str(0, pipeline->drd, pipeline->checkstrdrd);
        }
    }
  return (pipeline);
}

void		lign_t_multiple_pipeline(char *lign, t_sh_info *shell)
{
  char		**lines;
  t_pipeline	*tmp;
  int		i;

  i = 0;
  lines = my_str_to_wordtab(lign, ';', 0);
  if (lines != NULL)
    while (lines[i] != NULL)
      {
        tmp = pipeline_cced(lines[i], shell);
        shell->process_group = (t_pipeline**)add_ptr_t_tab(
                                 (void**)shell->process_group, (void*)tmp);
        while ((check_terminated_jobs(shell) == 0)
               && (shell->forground != NULL && shell->forground->running == 1))
          wait_all_jobs(shell->process_group);
        set_forground_pgrp(getpgid(shell->sh_pid));
        i++;
      }
  free(lines);
  free(lign);
}

void		getlaunch_prg(t_sh_info *shell)
{
  char		*lign;

  print_prompt(shell);
  shell->process_group = NULL;
  while ((lign = get_next_line(0)) != NULL)
    {
      if ((lign = check_and_load_backquote(lign, shell)) != NULL)
        lign_t_multiple_pipeline(lign, shell);
      print_prompt(shell);
    }
}
