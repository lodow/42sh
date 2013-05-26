/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat May 25 16:28:40 2013 luc sinet
*/

#include "42sh.h"

int	my_execve(char *path, char **argv, t_sh *shell)
{
  return (execve(path, argv, shell->env));
}

void	cmd_execution(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  cmd->pid.pid = -1;

  if (cmd->argv != NULL)
    {
      if (is_cmd_a_builtin(cmd, fd, shell, 1) == 0)
        exec_process(cmd, fd, shell, &my_execve);
    }
  close_fds(fd);
}

void	check_grp_set(int pid, int pgid)
{
  int	i;

  i = 0;
  while ((i < 100000000) && (pgid != check_perror("getpgid", getpgid(pid))))
    ++i;
}

int	exec_process(t_cmd *cmd, t_fds *fd, t_sh *shell,
                 int (*f)(char *cmd, char **argv, t_sh *shell))
{
  int	ret_exec;

  if ((cmd->pid.pid = check_perror("Fork", fork())) == 0)
    {
      if (cmd->pid.pgid != -1)
        {
          if (check_perror("Setpgid", setpgid(0, cmd->pid.pgid)) == -1)
            check_perror("Setpgid", setpgid(0, 0));
        }
      else
        check_perror("Setpgid", setpgid(0, 0));
      check_perror("Dup2", dup2(fd->stdin, 0));
      check_perror("Dup2", dup2(fd->stdout, 1));
      check_perror("Dup2", dup2(fd->stderr, 2));
      if ((ret_exec = f(cmd->cmd_fpath, cmd->argv, shell)) == -1)
        my_perror(cmd->cmd_fpath);
      my_exit(ret_exec);
      SETFLAG(shell->beepbeepexit, FLAGPOS(EXIT_FORK));
    }
  else if (cmd->pid.pid != -1)
    check_grp_set(cmd->pid.pid,
                  (cmd->pid.pgid == -1) ? cmd->pid.pid : cmd->pid.pgid);
  return (cmd->pid.pid);
}
