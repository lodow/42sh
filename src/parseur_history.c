/*
** parseur_history.c for parseur_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 24 09:54:35 2013 remi robert
** Last update Sun May 26 16:54:48 2013 luc sinet
*/

#include "42sh.h"

int	extract_cmd_history(char *cmd, t_history *history, char *str)
{
  int	indice;
  int	indice_nb;

  indice = 0;
  while (cmd != NULL && history != NULL &&
	 cmd[indice] != '\0')
    {
      if (cmd[indice] == '!')
	{
	  indice_nb = 1;
	  str[0] = '!';
	  while (cmd[indice] != '\0' && cmd[indice] >= '0' &&
		 cmd[indice] <= '9' && indice_nb < 12)
	    str[indice_nb++] = cmd[indice++];
	  str[indice_nb] = '\0';
	  if (str[1] != '\0')
	    return (1);
	}
      if (cmd[indice])
	++indice;
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
  char	*inter;

  if (my_strlen(*cmd) >= 2 && (*cmd)[0] == '!')
    {
      if ((*cmd)[1] == '!')
	inter = my_strdup(get_cmd_history(history,
					  nb_max_history(history) - 1));
      else
	inter = my_strdup(get_cmd_history(history, my_getnbr(&(*cmd)[1])));
      free(*cmd);
      *cmd = inter;
    }
}
