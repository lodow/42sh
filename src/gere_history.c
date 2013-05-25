/*
** gere_history.c for gere_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 16 14:59:38 2013 remi robert
** Last update Sat May 25 15:21:03 2013 Adrien Della Maggiora
*/

#include "42sh.h"

void	add_history_after_line(char *line, t_history **history)
{
  if (history != NULL && *history != NULL &&
      str_cmp((*history)->cmd, line) == 1 &&
      (my_strlen(line) == 1 && line[0] == ' '))
    return ;
  if (line != NULL && line[0] != '\0' && line[0] != '\n')
    add_history(history, line);
}

int		nb_max_history(t_history *history)
{
  t_history	*pcurrent;
  int		indice;

  if (history == NULL)
    return (0);
  indice = 0;
  pcurrent = history;
  while (pcurrent != NULL)
    {
      indice = indice + 1;
      pcurrent = pcurrent->next;
    }
  return (indice);
}

int	gere_pos_history(char *buff, int current_pos, int nb_max)
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

char		*return_pos_history(t_history *phead, int pos)
{
  int		indice;
  t_history	*pcurrent;

  if (phead == NULL)
    return (NULL);
  indice = 0;
  pcurrent = phead;
  if (pos == indice)
    return (phead->cmd);
  while (pcurrent != NULL && indice != pos)
    {
      if (indice + 1 == pos)
	return (pcurrent->cmd);
      pcurrent = pcurrent->next;
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
  if (history == NULL ||
      ((current_pos = gere_pos_history(buff, param->pos_history,
				       nb_max_history(history))) == -1 ||
       (s = return_pos_history(history, current_pos)) == NULL))
    {
      if (history != NULL && current_pos == -1)
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
