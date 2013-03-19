/*
** pipe.c for pipe in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Feb 28 16:48:04 2013 luc sinet
** Last update Mon Mar 11 13:37:01 2013 luc sinet
*/

#include <unistd.h>
#include "main.h"
#include "exec_cmd.h"

int	child_proc(t_sh *spt, char **cmd, int *fd, int i)
{
  close(fd[0]);
  dup2(fd[1], 1);
  close(fd[1]);
  if (rpipe(spt, cmd, i + 1) == -1)
    exit(-1);
  return (0);
}

int	parent_proc(t_sh *spt, char **cmd, int *fd)
{
  int	i;

  close(fd[1]);
  dup2(fd[0], 0);
  close(fd[0]);
  if ((i = get_next_sign(spt, cmd, spt->fa) + 1) > 0 && cmd[i - 1][0] == '>')
    {
      spt->sa = get_next_sign(spt, cmd, spt->fa) + 1;
      r_output(spt, cmd, NULL, 0);
    }
  else
    if (exec_pipe(spt, cmd, spt->fa) == -1)
      exit(-1);
  return (0);
}

int	last_pipe(t_sh *spt, char **cmd, int *fd)
{
  int	i;

  i = spt->fa;
  close(fd[1]);
  if ((i = get_next_sign(spt, cmd, spt->fa) + 1) > 0 && cmd[i - 1][0] == '>')
    {
      spt->sa = get_next_sign(spt, cmd, spt->fa) + 1;
      r_output(spt, cmd, NULL, 0);
    }
  else
    if (exec_pipe(spt, cmd, spt->fa) == -1)
      exit(-1);
  return (0);
}

int	rpipe(t_sh *spt, char **cmd, int i)
{
  int	fd[2];
  int	pid;

  if (i != 0)
    spt->fa = get_l_pipe(spt, cmd, spt->fa - 2);
  if (pipe(fd) == -1)
    merror("Pipe failed\n", -1);
  if (i < spt->nb_pipe + 1)
    {
      if ((pid = fork()) < 0)
	return (merror("Fork failed\n", -1));
      if (pid == 0)
	child_proc(spt, cmd, fd, i);
      else
	parent_proc(spt, cmd, fd);
    }
  else
    last_pipe(spt, cmd, fd);
  return (0);
}

int	r_pipe(t_sh *spt, char **cmd, char *fullpath, int ffd)
{
  int	i;
  int	pid;

  i = 0;
  spt->nb_pipe = 0;
  spt->cpid = 0;
  while ((spt->fa = get_next_sign(spt, cmd, spt->sa) + 1) > 0 &&
	 cmd[spt->fa - 1][0] == '|')
    {
      spt->sa = spt->fa;
      spt->nb_pipe++;
    }
  spt->fa = spt->sa;
  if ((pid = fork()) < 0)
    return (merror("Fork failed\n", -1));
  if (pid == 0)
    {
      rpipe(spt, cmd, 0);
      exit(0);
    }
  /* else */
  /*   waitpid(pid, NULL, 0); */
  return (0);
}
