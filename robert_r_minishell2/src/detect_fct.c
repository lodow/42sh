/*
** detect_fct.c for detect_fct in /home/remi/Projet/minishell/new_shell/env
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 13:27:46 2013 remi robert
** Last update Fri Mar  8 18:49:12 2013 remi
*/

#include "my_func.h"

int	exec_fonction(t_list **ptete, t_cmd **cmd, int indice, t_list **history)
{
  int	(*f[6])(t_list **ptete, t_cmd *cmd);

  f[0] = fct_exit;
  f[1] = fct_env;
  f[2] = fct_setenv;
  f[3] = fct_unsetenv;
  f[4] = fct_cd;
  f[5] = fct_echo;
  if (indice == 0)
    free_env(*history);
  if (indice != 6)
    f[indice](ptete, *cmd);
  if (indice == 6)
    return (fct_history(history, cmd));
  return (1);
}

int	detect_fct(t_list **ptete, t_cmd **cmd, t_list **history)
{
  char	*fct[7];
  int	indice;

  fct[0] = "exit";
  fct[1] = "env";
  fct[2] = "setenv";
  fct[3] = "unsetenv";
  fct[4] = "cd";
  fct[5] = "echo";
  fct[6] = "history";
  indice = 0;
  if (*cmd == NULL || (*cmd)->cmd == NULL || (*cmd)->cmd[0] == NULL)
    return (0);
  while (indice < 7)
    {
      if (str_cmp(fct[indice], (*cmd)->cmd[0]) == 1)
	{
	  return (exec_fonction(ptete,
				cmd, indice, history) != 0);
	}
      indice = indice + 1;
    }
  return (0);
}
