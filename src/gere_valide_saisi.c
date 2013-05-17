/*
** gere_valide_saisi.c for gere_valid_saisi in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr 12 12:46:34 2013 remi robert
** Last update Fri May 17 08:36:35 2013 remi robert
*/

#include "my_func.h"

int	recup_nb_history(char *str)
{
  char	buff[10];
  int	indice;

  indice = 0;
  while (indice < 8 && str[indice] != '\0')
    {
      if (str[indice] < '0' || str[indice] > '9')
	return (-1);
      buff[indice] = str[indice];
      indice = indice + 1;
    }
  buff[indice] = '\0';
  return (my_getnbr(buff));
}

char		*return_cmd_history_racourci(char *str,
					     t_history **history)
{
  int		nb;
  t_history	*pcourant;

  if (*history == NULL)
    return (NULL);
  if (str[0] != '\0' && str[0] == '!' && str[1] == '!')
    return ((*history)->cmd);
  if (str[0] != '\0' && str[0] == '!' && str[1] != '\0')
    {
      if ((nb = recup_nb_history(&str[1])) == -1)
	return (NULL);
      pcourant = *history;
      while (pcourant != NULL)
	{
	  if (pcourant->nb_history == nb)
	    return (pcourant->cmd);
	  pcourant = pcourant->next;
	}
      return (NULL);
    }
  return (NULL);
}

char	*check_cmd_history(char *str, t_history **history)
{
  int	indice;
  char	*cmd;

  if (str == NULL || *history == NULL)
    return (str);
  if (str[0] != '\0' && str[0] == '!')
    {
      if ((cmd = return_cmd_history_racourci(str, history)) == NULL)
	return (str);
      if (str != NULL)
	free(str);
      if ((str = malloc(my_strlen(cmd) + 1)) == NULL)
	return (NULL);
      indice = 0;
      while (cmd[indice] != '\0')
	{
	  str[indice] = cmd[indice];
	  indice = indice + 1;
	}
      str[indice] = '\0';
      return (str);
    }
  return (str);
}

char	*return_saisi(char *cmd, t_history **history)
{
  char	*str;
  int	indice;

  indice = -1;
  if ((str = malloc(my_strlen(cmd) + 1)) == NULL)
    return (cmd);
  while (cmd[++indice] != '\0' && indice < SIZE_BUFFER)
    str[indice] = cmd[indice];
  str[indice] = '\0';
  str = check_cmd_history(str, history);
  if (str == NULL)
    return (cmd);
  indice = -1;
  free(cmd);
  return (str);
}
