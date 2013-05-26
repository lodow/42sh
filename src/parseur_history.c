/*
** parseur_history.c for parseur_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 24 09:54:35 2013 remi robert
** Last update Sun May 26 14:35:37 2013 luc sinet
*/

#include "42sh.h"

int	extract_cmd_history(char *cmd, t_history *history, char *str)
{
  int	indice;
  int	indice_nb;

  indice = -1;
  while (cmd != NULL && history != NULL &&
	 cmd[++indice] != '\0')
    {
      if (cmd[indice] == '!')
	{
	  indice_nb = 0;
	  str[0] = '!';
	  str[1] = '\0';
	  while (cmd[++indice] != '\0' && cmd[indice] >= '0' &&
		 cmd[indice] <= '9' && ++indice_nb <= 10)
	    str[(indice_nb + 1)] = cmd[indice];
	  str[(indice_nb + 1)] = '\0';
	  if (str[1] != '\0')
	    return (1);
	}
    }
  return (0);
}

char	*cmd_copy_hist(char *cmd)
{
  char	*s;
  int	indice;

  if (cmd == NULL || (s = malloc(my_strlen(cmd) + 2)) == NULL)
    return (NULL);
  indice = 0;
  while (cmd[indice] != '\0')
    {
      s[indice] = cmd[indice];
      ++indice;
    }
  s[indice] = ' ';
  s[indice + 1] = '\0';
  free(cmd);
  return (s);
}

void	parseur_history(char **cmd, t_history *history)
{
  char	str[12];

  if ((*cmd = cmd_copy_hist(*cmd)) == NULL || history == NULL ||
      (*cmd = rempl_str_inib(*cmd, "!!", history->cmd, 1)) == NULL)
    return ;
  while (extract_cmd_history(*cmd, history, str) == 1)
    {
      if ((*cmd = rempl_str_inib(*cmd, str, get_cmd_history
				 (history, my_getnbr(&str[1])), 1))
	  == NULL)
	{
	  *cmd = NULL;
	  return ;
	}
    }
}
