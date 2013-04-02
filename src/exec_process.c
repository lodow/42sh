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

void	exec_process(t_cmd *cmd, t_sh *shell, t_pipe *grp)
{
  cmd->pid.pid = -1;
  if ((shell->env != NULL)/* && (special_cmd(cmd, shell, 1) == 0)*/)
    {
      if ((cmd->argv != NULL) && ((cmd->pid.pid = fork()) == 0))
        {
          signal(SIGINT, SIG_DFL);
          signal(SIGTTOU, SIG_DFL);
          signal(SIGTTIN, SIG_DFL);
          signal(SIGTSTP, SIG_DFL);
          setpgid(0, 0);
          dup2(cmd->fd.stdin, 0);
          dup2(cmd->fd.stdout, 1);
          dup2(cmd->fd.stderr, 2);
          //close_all_pipe(pipeline);
          execve(cmd->cmd_fpath, cmd->argv, shell->env);
      /*    if (cmd->fd.stdin != 0)
            cat(0, 1);
      */    my_putstr("What are you trying to do ? Fool !\n", 1, -1);
          exit(-1);
        }
    }
}
