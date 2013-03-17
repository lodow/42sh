/*
** run_loop.c for run_loop.c \ in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 09:53:57 2013 remi robert
** Last update Fri Mar  8 17:20:17 2013 remi
*/

#include "my_func.h"

void		run_loop(t_list *ptete)
{
  t_cmd		*cmd;
  t_list	*history;

  init_shell(&ptete);
  history = NULL;
  while (1)
    {
      prompt(ptete);
      gere_signal();
      cmd = read_cmd(ptete, &history);
      rm_first_lm_list(&history);
      if (cmd != NULL && cmd->cmd != NULL)
	parser_instruction(cmd, &ptete, &history);
      free_list_cmd(cmd);
    }
}
