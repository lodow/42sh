/*
** pipe.c for exec_pipe in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Feb 19 21:06:49 2013 remi robert
** Last update Sat Mar  9 11:20:37 2013 remi
*/

#include "my_func.h"

void	init_all_cmd(t_cmd **cmd, t_pipe *pipe)
{
  t_cmd	*pcourant;
  int	indice;

  if (*cmd == NULL || (*cmd)->next == NULL)
    return ;
  indice = 0;
  pcourant = *cmd;
  pipe->fd_file_rg = 0;
  pipe->fd_file_rd = 0;
  if (pcourant->type == 2)
    {
      pipe->pid[indice] = 0;
      pcourant = pcourant->next;
    }
  while (pcourant != NULL && test_type_cmd(pcourant->type) == 0)
    {
      pipe->pid[indice] = 0;
      pcourant = pcourant->next;
    }
}

void	close_all_fd(t_cmd *temp, int nb, t_pipe *pipe)
{
  t_cmd	*pcourant;
  int	indice;

  if (temp == NULL || temp->next == NULL)
    return ;
  pcourant = temp;
  indice = 0;
  if (pcourant->type == 2)
    {
      indice = 1;
      close(pcourant->fd[0]);
      close(pcourant->fd[1]);
      pcourant = pcourant->next;
    }
  while (indice < nb && pcourant != NULL && test_type_cmd(pcourant->type) == 0)
    {
      close(pcourant->fd[0]);
      close(pcourant->fd[1]);
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  if (pipe->fd_file_rg > 0)
    close(pipe->fd_file_rg);
  if (pipe->fd_file_rd > 0)
    close(pipe->fd_file_rd);
}

void	wait_all(t_pipe *pipe)
{
  int	indice;

  indice = 0;
  while (indice < pipe->nb_pipe && indice < 2048)
    {
      if (pipe->pid[indice] != 0)
	waitpid(pipe->pid[indice], NULL, 0);
      indice = indice + 1;
    }
}

int	number_pipe(t_cmd *temp)
{
  t_cmd	*pcourant;
  int	nb;

  if (temp == NULL && temp->next == NULL)
    return (0);
  pcourant = temp;
  nb = 0;
  if (pcourant->type == 2)
    {
      pcourant = pcourant->next;
      nb = 1;
    }
  while (pcourant != NULL &&
	 test_type_cmd(pcourant->type) == 0)
    {
      nb = nb + 1;
      pcourant = pcourant->next;
    }
  return (nb);
}
