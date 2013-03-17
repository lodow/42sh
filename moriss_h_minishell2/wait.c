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

void	aff_special_return_val(t_prg *cmd)
{
  char	*tmp;
  int	signal;

  cmd->done = 1;
  if (WIFSIGNALED(cmd->wait_satus))
    {
      signal = WTERMSIG(cmd->wait_satus);
      my_putstr(cmd->prg, 2, -1);
      my_putstr(" terminated by signal: 0x", 2, -1);
      tmp = my_uint_strbase(signal, "0123456789ABCDEF");
      my_putstr(tmp, 2, -1);
      free(tmp);
      my_putstr("\n", 2, -1);
      if (signal == 0xB)
        my_putstr("Segmentation fault\n", 2, -1);
    }
  if (WIFEXITED(cmd->wait_satus))
    cmd->return_val = WEXITSTATUS(cmd->wait_satus);
}

int	wait_son(t_pipeline *prgl, int start, int nb, int closeb)
{
  int	i;
  t_prg	*cmd;
  int	out;

  i = 0;
  if (start >= 0)
    i = start;
  if (closeb)
    close_all_pipe(prgl);
  while (i < nb)
    {
      cmd = prgl->prg_list[i];
      if ((cmd->done == 0) && (cmd->pidf != -1))
        {
          out = waitpid(cmd->pidf, &(cmd)->wait_satus, WNOHANG);
          if (out == 0)
            return (1);
          else
            aff_special_return_val(cmd);
        }
      i++;
    }
  return (0);
}
