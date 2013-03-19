/*
** exec_cmd.c for exec_cmd in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Feb 16 15:44:45 2013 luc sinet
** Last update Thu Mar  7 17:59:32 2013 luc sinet
*/

#include <unistd.h>
#include "main.h"
#include "exec_cmd.h"

int	check_next_cmd(t_sh *spt, char **cmd, char *fullpath)
{
  int	i;
  int	x;
  int	(*exe[4])(t_sh *spt, char **cmd, char *fullpath, int fd);

  x = 0;
  exe[0] = &r_input;
  exe[1] = &r_output;
  exe[2] = &r_pipe;
  exe[3] = &exec_cmd;
  spt->fa = 0;
  if ((spt->sa = get_next_sign(spt, cmd, spt->fa)) == -1)
    return (exe[3](spt, cmd, fullpath, -1));
  while (x < 5 && my_strcmp(spt->sign[x], cmd[spt->sa]) != 0)
    x++;
  spt->sa++;
  return (exe[x / 2](spt, cmd, NULL, -1));
}

int	exec_cmd(t_sh *spt, char **cmd, char *fullpath, int fd)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if (execve(fullpath, cmd, spt->menv) == -1)
  	exit(-1);
    }
  else
    wait(NULL);
  return (0);
}
