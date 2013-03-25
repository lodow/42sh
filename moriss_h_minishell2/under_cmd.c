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

void	rm_pipeline(t_pipeline *pipeline)
{
  int	i;

  i = 0;
  if (pipeline != NULL)
    {
      close_all_pipe(pipeline);
      while (i < pipeline->nb)
        {
          free_prg(pipeline->prg_list[i]);
          i++;
        }
      free(pipeline->checkstrdrd);
      free(pipeline->prg_list);
      free(pipeline->lign);
      free(pipeline);
    }
}

int	is_pipeline_exec_a(t_pipeline *pipeline)
{
  int	i;
  t_prg	*cmd;

  i = 0;
  if (pipeline == NULL)
    return (0);
  while (i < pipeline->nb)
    {
      cmd = (pipeline->prg_list[i]);
      if (!((cmd != NULL)
            && (special_cmd(cmd, NULL, 0) || is_executable(cmd))))
        {
          if (cmd->argv != NULL)
            my_putstr(cmd->argv[0], 2, -1);
          my_putstr(": command not found\n", 2, -1);
          return (0);
        }
      i++;
    }
  return (1);
}

t_pipeline	*lign_into_pipeligne(char *lign, t_sh_info *shell)
{
  char		**cmds;
  t_prg		*cmd;
  int		i;
  t_pipeline	*pipeline;

  i = 0;
  if ((pipeline = malloc(1 * sizeof(t_pipeline))) == NULL)
    return (NULL);
  pipeline->nb = 0;
  cmds = my_str_to_wordtab(lign, '|', 0);
  while ((cmds != NULL) && (cmds[pipeline->nb] != NULL))
    pipeline->nb++;
  if ((pipeline->prg_list = malloc(pipeline->nb * sizeof(t_prg*))) == NULL)
    return (NULL);
  while ((cmds != NULL) && (i < pipeline->nb))
    {
      if (((cmd = get_command(shell, cmds[i])) != NULL) && (cmd->line != NULL))
        pipeline->prg_list[i] = cmd;
      i++;
    }
  free(cmds);
  init_stdfd_t_def_val(&(pipeline->fd), 0, 1, 2);
  pipeline->drd = -1;
  pipeline->checkstrdrd = NULL;
  return (pipeline);
}
