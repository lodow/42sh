/*
** loop_parser_instruction.c for loop_parser in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Feb 22 09:47:31 2013 remi robert
** Last update Sat Mar  9 11:24:37 2013 remi
*/

#include "my_func.h"

int	check_fond_access_pipe(t_cmd **ptete, t_list *envp)
{
  t_cmd	*pcourant;

  if (ptete == NULL)
    return (0);
  pcourant = *ptete;
  while (pcourant != NULL &&
	 pcourant->type != 5 &&
	 pcourant->type != 3 &&
	 pcourant->type != 4 &&
	 pcourant->type != 2)
    {
      detect_alias(&pcourant, envp);
      if (find_cmd(pcourant, envp) == 0)
	 return (0);
      pcourant = pcourant->next;
    }
  return (1);
}

void	loop_exec(t_cmd **pcourant, t_list **ptete,
		  t_cmd *ptemp, t_list **history)
{
  (*pcourant)->type = 0;
  if (detect_pipe(*pcourant) == 1)
    {
      if (*pcourant == NULL || check_fond_access_pipe(pcourant, *ptete) == 0)
	return ;
      exec_pipe(pcourant, *ptete);
      return ;
    }
  detect_alias(pcourant, *ptete);
  if (detect_fct(ptete, pcourant, history) == 1)
    return ;
  exec_simple_command(pcourant, *ptete,
		      detect_redirection(*pcourant, 5),
		      detect_redirection(*pcourant, 3));
}

void	parser_instruction(t_cmd *cmd, t_list **ptete, t_list **history)
{
  t_cmd	*ptemp;
  t_cmd	*pcourant;

  if (cmd == NULL || cmd->cmd == NULL)
    return ;
  ptemp = cmd;
  pcourant = cmd;
  while (pcourant != NULL)
    {
      loop_exec(&pcourant, ptete, ptemp, history);
      if (increment_pos(&pcourant) == 1)
	return ;
    }
}
