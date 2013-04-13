/*
** history.c for history.c in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr 12 19:14:58 2013 remi robert
** Last update Sat Apr 13 10:07:02 2013 remi robert
*/

#include "../../include/42sh.h"

void		view_history(t_history *ptete)
{
  t_history	*pcourant;

  if (ptete == NULL)
    {
      my_putstr("NULL\n", 1, -1);
      return ;
    }
  pcourant = ptete;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  while (pcourant != NULL)
    {
      my_putstr(" ", 1, -1);
      my_put_nbr(pcourant->nb_history);
      my_putstr("  ", 1, -1);
      my_putstr(pcourant->cmd, 1, -1);
      my_putstr("\n", 1, -1);
      pcourant = pcourant->back;
    }
}

void		clear_history(t_history *ptr)
{
  if (ptr == NULL)
    return ;
  while (ptr->next != NULL)
    {
      ptr = ptr->next;
      if (ptr->back->cmd != NULL)
	free(ptr->back->cmd);
      free(ptr->back);
    }
  if (ptr->cmd != NULL)
    free(ptr->cmd);
  free(ptr);
}

void	builtin_history(t_sh *shell, t_cmd *cmd)
{
  if (shell == NULL || cmd == NULL)
    return ;
  if (cmd->argv[1] == NULL)
    {
      view_history(shell->history);
      return ;
    }
  if (cmd->argv[1] != NULL && str_cmp(cmd->argv[1], "-c") == 1)
    {
      clear_history((shell->history));
      shell->history = NULL;
      return ;
    }
  if (cmd->argv[1] != NULL && str_cmp(cmd->argv[1], "-d") == 1 &&
      cmd->argv[2] != NULL)
    {
      rm_history_d(&(shell->history), my_getnbr(cmd->argv[2]));
      return ;
    }
  my_putstr("history: usage: history [-c] [-d offset]\n", 1, -1);
}
