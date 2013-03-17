/*
** fct_cd.c for cd in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Feb 21 21:03:16 2013 remi robert
** Last update Sat Mar  9 11:04:32 2013 remi
*/

#include "my_func.h"

t_list		*return_env_pwd(t_list **ptete)
{
  t_list	*pcourant;

  if (*ptete == NULL)
    return (NULL);
  pcourant = *ptete;
  while (pcourant != NULL)
    {
      if (str_cmp_env(pcourant->tab, "PWD") == 1)
	return (pcourant);
      pcourant  = pcourant->next;
    }
  return (NULL);
}

int	exec_fct_cmd(t_list **ptete, t_cmd *cmd)
{
  t_list	*pwd;

  fct_cd_option(ptete);
  if ((pwd = return_env_pwd(ptete)) == NULL)
    return (0);
  if (cmd->cmd[1] == NULL)
    return (0);
  if (cmd->cmd[1][0] == '.')
    trunck_pwd(&pwd);
  if (cmd->cmd[1][0] == '/')
    ecrase_pwd(&pwd, cmd->cmd[1]);
  if (cmd->cmd[1][0] != '.' && cmd->cmd[1][0] != '/')
    add_pwd(&pwd, cmd->cmd[1]);
  return (1);
}

int		fct_cd(t_list **ptete, t_cmd *cmd)
{
  if (cmd == NULL || cmd->cmd == NULL || cmd->cmd[0] == NULL)
    return (0);
  if (cmd->cmd[1] == NULL)
    {
      fct_cd_home(ptete);
      return (0);
    }
  if (cmd->cmd[1] != NULL && cmd->cmd[1][0] != '-' && chdir(cmd->cmd[1]) == -1)
    {
      my_putstr("1. Path not found\n");
      return (0);
    }
  if (cmd->cmd[1][0] == '-')
    {
      fct_cd_moins(ptete);
      return (0);
    }
  return (exec_fct_cmd(ptete, cmd));
}
