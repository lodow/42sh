/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
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

int	exec_process(t_cmd *cmd, t_fds *fd, t_sh *shell,
                 int (*f)(char *cmd, char **argv, t_sh *shell))
{
  if ((cmd->pid.pid = fork()) == 0)
    {
      signal(SIGINT, SIG_DFL);
      signal(SIGTTOU, SIG_DFL);
      signal(SIGTTIN, SIG_DFL);
      signal(SIGTSTP, SIG_DFL);
      signal(SIGCHLD, SIG_DFL);
      setpgid(0, 0);
      dup2(fd->stdin, 0);
      dup2(fd->stdout, 1);
      dup2(fd->stderr, 2);
      close_fds(fd);
      my_exit(f(cmd->cmd_fpath, cmd->argv, shell));
    }
  return (cmd->pid.pid);
}
