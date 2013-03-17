/*
** exit.c for exit in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 10:56:29 2013 remi robert
** Last update Fri Mar  8 08:50:54 2013 remi
*/

#include "my_func.h"

/*
** REcupérer argument pour exit
*/
int	fct_exit(t_list **ptete, t_cmd *cmd)
{
  int	ret;

  if (cmd == NULL || cmd->cmd == NULL ||
      cmd->cmd[0] == NULL || cmd->cmd[1] == NULL)
    ret = 0;
  else
    ret = my_getnbr(cmd->cmd[1]);
  free_env(*ptete);
  free_list_cmd(cmd);
  my_putstr("\n");
  exit(ret);
  return (0);
}
