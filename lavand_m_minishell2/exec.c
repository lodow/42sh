/*
** exec.c for minishell in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Mon Dec 10 10:22:39 2012 maxime lavandier
** Last update Thu Mar  7 23:15:00 2013 maxime lavandier
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_list.h"
#include "str_to_wordtab.h"

void	exec_com(char *com, char *str, char **env, t_pipe *pipee)
{
  pid_t		pid;
  int		status;

  if ((pid = fork()) == -1)
    {
      my_putstr("Fork error.");
      exit(0);
    }
  if (pid == 0)
    {
      my_dup(pipee);
      str = redir_fin(str, pipee);
      execve(com, str_to_wordtab(str, ' ', pipee->ptete, -1), env);
      my_putstr(com);
      my_putstr(" : Not found\n");
      exit(0);
    }
  else if (pipee->state == 1 || pipee->state == 3)
    {
      close(pipee->fd_before[0]);
      close(pipee->fd_before[1]);
    }
  wait(NULL);
}

int	exec_cmd2(char *str, char **env,
		  char ***basic_env, t_pipe *pipee)
{
  int	i;

  i = 0;
  if (my_strcmp_force(str, "exit"))
    delete_list(pipee->ptete->ptete);
  if (search2(str) == 1)
    {
      exec_com(str, str, *basic_env, pipee);
      return (0);
    }
  while (env[i] != 0)
    {
      if (search(env[i], str) == 1)
	{
	  exec_com(my_strcat(env[i], str, pipee->ptete), str,
		   *basic_env, pipee);
	  return (0);
	}
      i++;
    }
  other(str, basic_env, pipee->ptete);
  return (0);
}

int		exec_cmd(char *str, t_malloc *ptete, char **env,
			 char ***basic_env)
{
  char		**com;
  int		f;
  t_pipe	pipee;

  com = str_to_wordtab(str, '|', ptete, -1);
  f = -1;
  pipee.fd_after[0] = 0;
  pipee.fd_after[1] = 1;
  pipee.ptete = ptete;
  while (com != 0 && com[++f] != 0)
    {
      pipee.fd_before[0] = pipee.fd_after[0];
      pipee.fd_before[1] = pipee.fd_after[1];
      pipee.state = 0;
      if (f > 0)
	pipee.state += 1;
      if (com[f + 1] != 0)
	{
	  pipee.state += 2;
	  if (pipe(pipee.fd_after) == -1)
	    exit(0);
	}
      exec_cmd2(com[f], env, basic_env, &pipee);
    }
  return (0);
}
