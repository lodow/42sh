/*
** free.c for free.c in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 10:24:51 2013 remi robert
** Last update Mon Mar 11 10:54:43 2013 remi
*/

#include "my_func.h"

void	free_env(t_list *ptete)
{
  if (ptete == NULL)
    return ;
  while (ptete->next != NULL)
    {
      ptete = ptete->next;
      if (ptete->back->tab != NULL)
	free(ptete->back->tab);
      free(ptete->back);
    }
  if (ptete->tab != NULL)
    free(ptete->tab);
  free(ptete);
}

void	free_tab_cmd(char **tab_cmd)
{
  int	indice;

  indice = 0;
  if (tab_cmd == NULL)
    return ;
  while (tab_cmd[indice] != NULL)
    {
      free(tab_cmd[indice]);
      indice = indice + 1;
    }
  free(tab_cmd);
}

void	free_list_cmd(t_cmd *cmd)
{
  if (cmd == NULL)
    return ;
  while (cmd->next != NULL)
    {
      cmd = cmd->next;
      free_tab_cmd(cmd->back->cmd);
      free(cmd->back);
    }
  free_tab_cmd(cmd->cmd);
  free(cmd);
}
