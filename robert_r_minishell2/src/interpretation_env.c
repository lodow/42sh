/*
** interpretation_env.c for interpretation in /home/remi/Projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar  7 09:00:13 2013 remi
** Last update Sat Mar  9 11:12:43 2013 remi
*/

#include "my_func.h"

void	return_indice_pos_env(char *cmd, char *env, int *temp)
{
  int	indice;
  int	indice_tab;

  indice = 0;
  while (cmd[indice] != '\0' && cmd[indice] != '$')
    indice = indice + 1;
  *temp = indice;
  if (cmd[indice] == '\0' || cmd[indice] == '\0')
    {
      env[0] = '\0';
      return ;
    }
  indice = indice + 1;
  indice_tab = 0;
  while (cmd[indice] != '\0' && cmd[indice] != ' ' && cmd[indice] != '\t' &&
	 indice_tab < 511)
    {
      env[indice_tab] = cmd[indice];
      indice_tab = indice_tab + 1;
      indice = indice + 1;
    }
  env[indice_tab] = '\0';
}

char		*return_char_pos_env(char *cmd, t_list *ptete)
{
  t_list	*pcourant;

  if (ptete == NULL)
    return (NULL);
  pcourant = ptete;
  while (pcourant != NULL)
    {
      if (str_cmp_env(pcourant->tab, cmd) == 1)
	return (&(pcourant->tab[my_strlen(cmd) + 1]));
      pcourant = pcourant->next;
    }
  return (NULL);
}

int	recup_indice_after_cmd(char *cmd, int indice)
{
  while (cmd[indice] != ' ' && cmd[indice] != '\0')
    indice = indice + 1;
  if (cmd[indice] == '\0')
    return (-1);
  return (indice);
}

void	create_new_cmd_string(char *cmd, char *env,
			      char *copy_buff, int indice)
{
  int	indice_cmd;
  int	indice_tab;

  if (cmd == NULL || env == NULL || copy_buff == NULL)
    return ;
  indice_cmd = indice;
  indice_tab = 0;
  while (env[indice_tab] != '\0')
    {
      cmd[indice_cmd] = env[indice_tab];
      indice_cmd = indice_cmd + 1;
      indice_tab = indice_tab + 1;
    }
  cmd[indice_cmd] = '\0';
  if ((indice = recup_indice_after_cmd(copy_buff, indice)) == -1)
    return ;
  while (copy_buff[indice] != '\0')
    {
      cmd[indice_cmd] = copy_buff[indice];
      indice_cmd = indice_cmd + 1;
      indice = indice + 1;
    }
  cmd[indice_cmd] = '\0';
}

void	interpretation_env(char *cmd, t_list *ptete)
{
  char	env[512];
  char	*find;
  int	indice;
  char	copy_buff[8192];

  if (cmd == NULL || cmd[0] == '\0' ||  ptete == NULL)
    return ;
  return_indice_pos_env(cmd, env, &indice);
  if (env[0] == '\0' ||
      (find = return_char_pos_env(env, ptete)) == NULL ||
      my_strlen(cmd) + my_strlen(find) >= 8192)
    return ;
  copy_inter_buff(copy_buff, cmd);
  create_new_cmd_string(cmd, find, copy_buff, indice);
}
