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
  int	pid;

  pid = 0;
  set_forground_process(pid);
}

void	builtin_bg(t_prg *cmd, t_sh_info *shell)
{
  /*  kill(-cmd->pidf, SIGCONT);*/
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
