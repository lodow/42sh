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

void	init_stdfd_t_def_val(t_stdfd *fds, int stdin, int stdout, int stderr)
{
  fds->stdin = 0;
  fds->stdout = 1;
  fds->stderr = 2;
  if (stdin != -1)
    fds->stdin = stdin;
  if (stdout != -1)
    fds->stdout = stdout;
  if (stderr != -1)
    fds->stderr = stderr;
}

void		close_cmd_stdfds(t_prg *cmd)
{
  t_stdfd	*fd;

  if (cmd != NULL)
    {
      fd = &(cmd->fd);
      closefd_check(fd->stdin);
      closefd_check(fd->stdout);
      closefd_check(fd->stderr);
    }
}

void	close_all_pipe(t_pipeline *pipeline)
{
  int	i;
  t_prg	*cmd;

  i = 0;
  closefd_check(pipeline->fd.stdin);
  closefd_check(pipeline->fd.stdout);
  closefd_check(pipeline->fd.stderr);
  closefd_check(pipeline->drd);
  while (i < pipeline->nb)
    {
      cmd = pipeline->prg_list[i];
      close_cmd_stdfds(cmd);
      i++;
    }
}

int	pipe_it(t_pipeline *pipeline, t_prg *cmd, char ***envp)
{
  int	i;
  int	pipefd[2];
  t_prg	*lastcmd;

  i = 1;
  lastcmd = NULL;
  while (i < pipeline->nb)
    {
      if (pipe(pipefd) == -1)
        return (-1);
      cmd->fd.stdout = pipefd[PIPE_WRITE];
      exec_process(cmd, envp, pipeline);
      close_cmd_stdfds(lastcmd);
      wait_son(pipeline, i - 10, i - 3, 0);
      lastcmd = cmd;
      cmd = pipeline->prg_list[i];
      cmd->fd.stdin = pipefd[PIPE_READ];
      cmd->fd.stderr = pipeline->fd.stderr;
      cmd->fd.stdout = pipeline->fd.stdout;
      i++;
    }
  exec_process(cmd, envp, pipeline);
  close_cmd_stdfds(cmd);
  return (0);
}

int	pipe_exec_pipeline(t_pipeline *pipeline, char ***envp)
{
  t_prg	*cmd;

  if (pipeline->nb > 0)
    {
      cmd = pipeline->prg_list[0];
      cmd->fd.stdin = pipeline->fd.stdin;
      cmd->fd.stderr = pipeline->fd.stderr;
      cmd->fd.stdout = pipeline->fd.stdout;
      return (pipe_it(pipeline, cmd, envp));
    }
  return (0);
}
