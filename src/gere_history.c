/*
** gere_history.c for gere_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 16 14:59:38 2013 remi robert
** Last update Fri May 24 00:46:47 2013 remi robert
*/

#include "42sh.h"

int             nb_max_history(t_history *history)
{
  t_history     *pcourant;
  int           indice;

  if (history == NULL)
    return (0);
  indice = 0;
  pcourant = history;
  while (pcourant != NULL)
    {
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  return (indice);
}

int     gere_pos_history(char *buff, int current_pos, int nb_max)
{
  if (str_cmp(buff, STR_UP) == 1)
    {
      current_pos = current_pos + 1;
      if (current_pos > nb_max)
	current_pos = current_pos - 1;
      return (current_pos);
    }
  if (str_cmp(buff, STR_DOWN) == 1)
    {
      current_pos = current_pos - 1;
      if (current_pos < 1)
	{
	  current_pos = current_pos + 1;
	  return (-1);
	}
      return (current_pos);
    }
  return (-1);
}

char            *return_pos_history(t_history *ptete, int pos)
{
  int           indice;
  t_history     *pcourant;

  if (ptete == NULL)
    return (NULL);
  indice = 0;
  pcourant = ptete;
  if (pos == indice)
    return (ptete->cmd);
  while (pcourant != NULL && indice != pos)
    {
      if (indice + 1 == pos)
	return (pcourant->cmd);
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  return (NULL);
}

void	gere_history(char *cmd, t_param *param,
		     t_history *history, char *buff)
{
  int	current_pos;
  int	indice;
  char	*s;

  current_pos = 0;
  if ((current_pos =
       gere_pos_history(buff, param->pos_history,
			nb_max_history(history))) == -1 ||
      (s = return_pos_history(history, current_pos)) == NULL)
    {
      if (current_pos == -1)
	{
	  param->pos_history = 0;
	  param->pos = 0;
	  cmd[0] = '\0';
	  view(cmd, param);
	}
      return ;
    }
  param->pos_history = current_pos;
  indice = -1;
  while (s[++indice] != '\0' && indice < SIZE_BUFFER - 1)
    cmd[indice] = s[indice];
  cmd[indice] = '\0';
  param->pos = my_strlen(s);
  view(cmd, param);
}
