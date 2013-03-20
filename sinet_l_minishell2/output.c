/*
** output.c for output in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Feb 28 16:47:45 2013 luc sinet
** Last update Sun Mar 10 19:21:15 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

int		change_out(t_sh *spt, char **cmd, int op)
{
  int		fd;
  mode_t	mode;
  char		*save_sign;

  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  if (op == 0 &&
      (fd = open(cmd[spt->sa], O_WRONLY | O_CREAT | O_TRUNC, mode)) == -1)
    return (-1);
  else if (op == 1 &&
	   (fd = open(cmd[spt->sa], O_WRONLY | O_APPEND, mode)) == -1)
    return (-1);
  spt->old_fd = dup(1);
  dup2(fd, 1);
  close(fd);
  return (0);
}

int		r_output(t_sh *spt, char **cmd, char *fullpath, int fd)
{
  pid_t		pid;
  int		opt;

  if (my_strcmp(">>", cmd[spt->sa - 1]) == 0)
    opt = 1;
  else
    opt = 0;
  if (change_out(spt, cmd, opt) == -1 || (pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if (exec_pipe(spt, cmd, spt->fa) == -1)
	exit(0);
    }
  else
    wait(NULL);
  dup2(spt->old_fd, 1);
  close(spt->old_fd);
  return (0);
}
