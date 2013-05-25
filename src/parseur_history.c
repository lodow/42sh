/*
** parseur_history.c for parseur_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 24 09:54:35 2013 remi robert
** Last update Sat May 25 18:30:32 2013 remi robert
*/

#include "42sh.h"

/* char		*get_cmd_history(t_history *history, int nb) */
/* { */
/*   t_history	*pcourant; */

/*   if (history == NULL) */
/*     return (NULL); */
/*   pcourant = history; */
/*   while (pcourant != NULL) */
/*     { */
/*       if (pcourant->nb_history == nb) */
/* 	return (pcourant->cmd); */
/*       pcourant = pcourant->next; */
/*     } */
/*   return (NULL); */
/* } */

void	init_loop_parser(int *indice_nb, char *str)
{
  *indice_nb = -1;
  str[0] = '!';
  str[1] = '\0';
}

int	extract_cmd_history(char *cmd, t_history *history, char *str)
{
  int	indice;
  int	indice_nb;

  indice = -1;
  while (cmd != NULL && history != NULL &&
	 ++indice < (SIZE_BUFFER - 1) && cmd[indice] != '\0')
    {
      if (cmd[indice] == '!')
	{
	  init_loop_parser(&indice_nb, str);
	  while (cmd[++indice] != '\0' && cmd[indice] >= '0' &&
		 cmd[indice] <= '9')
	    str[(++indice_nb + 1) % 9] = cmd[indice];
	  str[(indice_nb + 1) % 9] = '\0';
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
  indice = -1;
  while (cmd[indice] != '\0')
    s[indice] = cmd[indice];
  if (indice < my_strlen(cmd) - 2)
    {
      s[indice] = ' ';
      s[++indice] = '\0';
    }
  else
    s[++indice] = '\0';
  free(cmd);
  return (s);
}

char	*parseur_history(char *cmd, t_history *history)
{
  char	str[12];

  if ((cmd = cmd_copy_hist(cmd)) == NULL || history == NULL ||
      (cmd = rempl_str_inib(cmd, "!!", history->cmd, 1)) == NULL)
    return (cmd);
  while (extract_cmd_history(cmd, history, str) == 1)
    {
      if ((cmd = rempl_str_inib(cmd, str,
				get_cmd_history(history, my_getnbr(&str[1])), 1))
	  == NULL)
	return (NULL);
    }
  cmd[my_strlen(cmd) - 1] = '\0';
  return (cmd);
}
