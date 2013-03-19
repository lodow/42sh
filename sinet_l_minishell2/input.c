/*
** input.c for input in /home/sinet_l//minishell2-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Mar 10 18:38:35 2013 luc sinet
** Last update Sun Mar 10 19:05:20 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"
#include "exec_cmd.h"
#include "get_next_line.h"

int		change_in(t_sh *spt, char **cmd)
{
  int		fd;
  char		*save_sign;

  if ((fd = open(cmd[spt->sa], O_RDONLY)) == -1)
    {
      my_putstr(cmd[spt->sa], 2);
      my_putstr(": No such file or directory.\n", 2);
      return (-1);
    }
  spt->old_fd = dup(0);
  dup2(fd, 0);
  close(fd);
  return (0);
}

char		**bufferise(char **buf, char *line, int pos)
{
  int		i;
  char		**new_buf;

  i = 0;
  if ((buf[pos] = my_strdup(line)) == NULL)
    return (NULL);
  free(line);
  if (((pos + 2) % 256) == 0)
    {
      if ((new_buf = malloc(sizeof(char *) * (pos + 2 + 256))) == NULL)
	return (NULL);
      while (i <= pos)
	{
	  if ((new_buf[i] = my_strdup(buf[i])) == NULL)
	    return (NULL);
	  free(buf[i++]);
	}
      free(buf);
      return (new_buf);
    }
  return (buf);
}

int		display_buf(t_sh *spt, char **cmd, char **buf)
{
  int		fd[2];
  int		pid[2];

  if ((pid[0] = fork()) == -1)
    return (merror("fork failed\n", -1));
  if (pid[0] == 0)
    {
      if (pipe(fd) < 0)
	return (merror("pipe failed\n", -1));
      if ((pid[1] = fork()) == -1)
	return (merror("fork failed\n"));
      if (pid[1] == 0)
	display_saved_buf(fd, buf, 0);
      else
	{
	  close(fd[1]);
	  dup2(fd[0], 0);
	  close(fd[0]);
	  exec_pipe(spt, cmd, spt->fa);
	}
    }
  else
    waitpid(pid[0], NULL, 0);
  return (0);
}

int		double_input(t_sh *spt, char **cmd)
{
  char		**buf;
  char		*line;
  int		state;

  state = 0;
  if ((buf = malloc(sizeof(char *) * 256)) == NULL)
    return (-1);
  while (state >= 0)
    {
      my_putstr("? ", 1);
      if ((line = get_next_line(0)) == NULL ||
	  my_strcmp(line, cmd[spt->sa]) == 0)
	{
	  free(line);
	  buf[state] = '\0';
	  state = -2;
	}
      if (state >= 0)
	if ((buf = bufferise(buf, line, state)) == NULL)
	  return (merror("Malloc failed", -1));
      state++;
    }
  display_buf(spt, cmd, buf);
  return (0);
}

int		r_input(t_sh *spt, char **cmd, char *fullpath, int fd)
{
  pid_t		pid;

  spt->sa = get_next_sign(spt, cmd, spt->fa) + 1;
  if (my_strcmp("<<", cmd[spt->sa - 1]) == 0)
    double_input(spt, cmd);
  else
    {
      if (change_in(spt, cmd) == -1 || (pid = fork()) == -1)
	return (-1);
      if (pid == 0)
	{
	  if (exec_pipe(spt, cmd, spt->fa) == -1)
	    exit(-1);
	}
      else
	waitpid(pid, NULL, 0);
      dup2(spt->old_fd, 0);
      close(spt->old_fd);
    }
  return (0);
}
