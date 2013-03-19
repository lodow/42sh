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

void	print_prompt(char **envp)
{
  char	*prompt;
  char	*ps1;

  if ((ps1 = get_envvar("PS1", envp)) != NULL)
    {
      if ((prompt = check_vars_in_str(ps1, envp)) != NULL)
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

void		pipeline_cced(char *lign, char ***envp)
{
  t_pipeline	*pipeline;

  pipeline = lign_into_pipeligne(lign, *envp);
  if ((pipeline != NULL) && (is_pipeline_exec_a(pipeline) != 0))
    {
      check_and_set_redirection(pipeline);
      if (pipe_exec_pipeline(pipeline, envp) != -1)
        {
          if (pipeline->drd != -1)
            cat_t_str(0, pipeline->drd, pipeline->checkstrdrd);
          while (wait_son(pipeline, 0, pipeline->nb, 1));
        }
    }
  rm_pipeline(pipeline);
  free(lign);
}

void	lign_t_multiple_pipeline(char *lign, char ***envp)
{
  char	**lines;
  int	i;

  i = 0;
  lines = my_str_to_wordtab(lign, ';', 0);
  if (lines != NULL)
    while (lines[i] != NULL)
      {
        pipeline_cced(lines[i], envp);
        i++;
      }
  free(lines);
  free(lign);
}

void		getlaunch_prg(char ***envp)
{
  char		*lign;

  print_prompt(*envp);
  signal(SIGINT, &get_signal);
  while ((lign = get_next_line(0)) != NULL)
    {
      if ((lign = check_and_load_backquote(lign, envp)) != NULL)
        lign_t_multiple_pipeline(lign, envp);
      signal(SIGINT, &get_signal);
      print_prompt(*envp);
    }
}