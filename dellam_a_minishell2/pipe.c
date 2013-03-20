/*
** pipe.c for pipe in /home/dellam_a/Projet/SVN/minishell1-2017-dellam_a
**
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
**
** Started on  Wed Feb  6 13:00:56 2013 Adrien dellamaggiora
** Last update Wed Mar 20 14:11:38 2013 remi
*/

#include "my.h"

int	check_pipe(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '|')
	return (1);
      i++;
    }
  return (0);
}

int	check_cmd(char **cmd, char **path)
{
  int	i;
  int	j;
  int	nb;
  char	*str;

  j = 0;
  nb = 0;
  while (path[j] != NULL)
    {
      i = 0;
      while (cmd[i] != NULL)
	{
	  str = fullpath(path[j], cmd[i]);
	  if (access(str, F_OK | X_OK) == 0
	      || access(cmd[i], F_OK | X_OK) == 0)
	    ++nb;
	  ++i;
	  free(str);
	}
      ++j;
    }
  if (i <= nb)
    return (1);
  else
    return (0);
}

void	fils(int fd[2], int fdin, char *cmd, t_cmd *sh)
{
  if (fd[1] != -1)
    {
      dup2(fd[1], 1);
      close(fd[1]);
    }
  else if (cmd != NULL)
    {
      dup2(fd[1], 1);
      close(fd[0]);
      close(fd[1]);
    }
  dup2(fdin, 0);
  if (fdin != 0)
    close(fdin);
  if (execve(sh->tmps, sh->opt, sh->env) == -1)
    {
      my_putstr("Execve failed\n");
      exit(0);
    }
}

int	closepipe(int fd[2], int fdin, char *cmd)
{
  if (fdin != 0)
    close(fdin);
  if (cmd == NULL)
    {
      fdin = 0;
      if (fd[0] != -1)
	close(fd[0]);
    }
  else if (fd[0] != -1)
    fdin = fd[0];
  if (fd[1] != -1)
    close(fd[1]);
  return (fdin);
}

void		my_fork(char *str, t_cmd *sh, char *cmd)
{
  int		fd[2];
  int		pid;
  int		red;

  fd[0] = -1;
  fd[1] = -1;
  sh->tmps = str;
  if ((red = check_redir(sh->opt)) > 0 && cmd == NULL)
    if ((fd[1] = my_redirec(red, sh->opt)) != -1 ||
	(sh->fdin = redirg(red, sh->opt)) != -1)
      sh->opt = rm_redir(sh->opt);
    else
      return ;
  else if (cmd != NULL)
    if (pipe(fd) == -1)
      return ;
  if ((pid = fork()) == -1)
    my_putstr("Fork failed !");
  else if (pid > 0)
    sh->pid = add_pid(sh->pid, pid);
  else
    fils(fd, sh->fdin, cmd, sh);
  sh->fdin = closepipe(fd, sh->fdin, cmd);
}
