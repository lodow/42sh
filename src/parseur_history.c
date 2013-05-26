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
