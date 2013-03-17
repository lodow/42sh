/*
** exec_pipe.c for exec_pipe in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Feb 22 09:51:48 2013 remi robert
** Last update Wed Mar  6 18:32:16 2013 remi
*/

#include "my_func.h"

int	first_pipe(t_cmd **pcourant, t_list *ptete, t_pipe *s_pipe, int red)
{
  s_pipe->fd_file_rg = 0;
  if (red == 5)
    s_pipe->fd_file_rg =
      open_file(5, return_name_file_redirection(*pcourant, 5),
		&(s_pipe->fd_file_rg));
  if (pipe((*pcourant)->fd) == -1 ||
      ((s_pipe)->pid[(s_pipe)->indice] = fork()) == -1)
    return (0);
  if ((s_pipe)->pid[(s_pipe)->indice] == 0)
    {
      close((*pcourant)->fd[0]);
      if (red == 5)
	dup2(s_pipe->fd_file_rg, 0);
      dup2((*pcourant)->fd[1], 1);
      execve((*pcourant)->path, (*pcourant)->cmd, return_env(ptete));
      exit(0);
    }
  return (1);
}

int	inter_pipe(t_cmd **pcourant, t_list *ptete, t_pipe *s_pipe)
{
  if (pipe((*pcourant)->fd) == -1 ||
      (s_pipe->pid[s_pipe->indice] = fork()) == -1)
    return (0);
  if (s_pipe->pid[s_pipe->indice] == 0)
    {
      dup2((*pcourant)->back->fd[0], 0);
      dup2((*pcourant)->fd[1], 1);
      close((*pcourant)->back->fd[1]);
      close((*pcourant)->fd[0]);
      execve((*pcourant)->path, (*pcourant)->cmd, return_env(ptete));
      exit(0);
    }
   close((*pcourant)->back->fd[1]);
   close((*pcourant)->back->fd[0]);
   return (1);
}

int	last_pipe(t_cmd **pcourant, t_list *ptete, t_pipe *s_pipe, int red)
{
  s_pipe->fd_file_rd = 0;
  if (red == 3 || red == 4)
    s_pipe->fd_file_rd =
      open_file(red, return_name_file_redirection(*pcourant, red),
		&(s_pipe->fd_file_rd));
  if ((s_pipe->pid[s_pipe->indice] = fork()) == -1)
    return (0);
  if (s_pipe->pid[s_pipe->indice] == 0)
    {
      close((*pcourant)->back->fd[1]);
      dup2((*pcourant)->back->fd[0], 0);
      if (red != 0)
	dup2(s_pipe->fd_file_rd, 1);
      execve((*pcourant)->path, (*pcourant)->cmd, return_env(ptete));
      exit(0);
    }
  return (1);
}

void		exec_pipe(t_cmd **pcourant, t_list *ptete)
{
  t_pipe	pipe;

  pipe.ptemp = *pcourant;
  pipe.indice = 0;
  init_all_cmd(pcourant, &pipe);
  pipe.nb_pipe = number_pipe(*pcourant);
  if (first_pipe(pcourant, ptete, &(pipe),
		 detect_redirection(*pcourant, 5)) == 0)
    return ;
  (*pcourant) = (*pcourant)->next;
  pipe.indice = pipe.indice + 1;
  while ((*pcourant)->next != NULL && (*pcourant)->next->type != 2 &&
	 (*pcourant)->next->type != 5 && (*pcourant)->next->type != 3 &&
	 (*pcourant)->next->type != 4 && pipe.indice < 512)
    {
      if (inter_pipe(pcourant, ptete, &pipe) == 0)
	return ;
      (*pcourant) = (*pcourant)->next;
      pipe.indice = pipe.indice + 1;
    }
  if (last_pipe(pcourant, ptete, &pipe,
		detect_redirection(*pcourant, 3)) == 0)
    return ;
  close_all_fd(pipe.ptemp, pipe.indice, &pipe);
  wait_all(&pipe);
}
