/*
** parser_instruction.c for parser in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 14:07:54 2013 remi robert
** Last update Sat Mar  9 11:45:21 2013 remi
*/

#include "my_func.h"

int    	detect_pipe(t_cmd *temp)
{
  t_cmd	*pcourant;

  if (temp == NULL || temp->next == NULL)
    return (0);
  pcourant = temp->next;
  while (pcourant != NULL && pcourant->type != 2)
    {
      if (pcourant->type == 1)
	return (1);
      pcourant = pcourant->next;
    }
  return (0);
}

int	detect_redirection(t_cmd *temp, int type)
{
  t_cmd	*pcourant;
  int	type_seconde;
  int	select;

  if (temp == NULL || temp->next == NULL)
    return (0);
  if (type == 5)
    type_seconde = 5;
  else
    type_seconde = 4;
  pcourant = temp;
  if (pcourant->type == 2)
    pcourant = pcourant->next;
  select = 0;
  while (pcourant != NULL && pcourant->type != 2)
    {
      if (pcourant->type == type || pcourant->type == type_seconde)
	select = pcourant->type;
      pcourant = pcourant->next;
    }
  return (select);
}

char	*return_name_file_redirection(t_cmd* temp, int type)
{
  t_cmd	*pcourant;
  char	*s;

  if (temp == NULL || temp->next == NULL)
    return (NULL);
  pcourant = temp;
  if (pcourant->type == 2)
    pcourant = pcourant->next;
  s = NULL;
  while (pcourant != NULL && pcourant->type != 2)
    {
      if (pcourant->type == type &&
	  pcourant->cmd != NULL && pcourant->cmd[0] != NULL)
	s = pcourant->cmd[0];
      pcourant = pcourant->next;
    }
  return (s);
}

int	increment_pos(t_cmd **pcourant)
{
  if (*pcourant == NULL && (*pcourant)->next == NULL)
    return (1);
  *pcourant = (*pcourant)->next;
  while ((*pcourant) != NULL && (*pcourant)->type != 2)
    *pcourant = (*pcourant)->next;
  if ((*pcourant) == NULL)
    return (1);
  return (0);
}

void	exec_simple_command(t_cmd **pcourant, t_list *ptete,
			    int red_g, int red_d)
{
  int	pid;
  int	file[2];

  if (find_cmd(*pcourant, ptete) == 0)
    return ;
  open_file_cmd(file, pcourant, red_g, red_d);
  pid = fork();
  if (pid == 0)
    {
      if (red_g != 0)
	dup2(file[0], 0);
      if (red_d != 0)
	dup2(file[1], 1);
      execve((*pcourant)->path,
	     (*pcourant)->cmd, return_env(ptete));
      exit(0);
    }
  else
    waitpid(pid, NULL, 0);
  close_file_cmd(file);
}
