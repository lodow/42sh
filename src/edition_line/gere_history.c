/*
** gere_history.c for gere_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr 12 13:13:10 2013 remi robert
** Last update Sun Apr 14 13:38:24 2013 remi robert
*/

#include "../include/my_func.h"

int		nb_max_history(t_history *history)
{
  t_history	*pcourant;
  int		indice;

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

void	add_current_history(t_history **history, char *str)
{
  int	indice;

  if (*history == NULL || str == NULL ||
      ((*history)->cmd = malloc(my_strlen(str) + 1)) == NULL)
    return ;
  indice = 0;
  while (str[indice] != '\0')
    {
      (*history)->cmd[indice] = str[indice];
      indice = indice + 1;
    }
  (*history)->cmd[indice] = '\0';
}

void	add_history_current_cmd(t_param **param, t_history **history)
{
  char	*str;

  str = return_string((*param)->string);
  if (str == NULL || str[0] == '\n' || str[0] == '\0')
    return ;
  if (*history == NULL)
    {
      add_history(history, str);
      free(str);
      return ;
    }
  add_current_history(history, str);
  free(str);
}

/*
** decommenter pour faire historique sur les commandes courantes;
*/
void		gere_history(t_param **param, char *buff, t_history **history)
{
  int		ret;
  /* static char	*old_cmd; */

  if (*param == NULL || buff == NULL || *history == NULL)
    return ;
  /* old_cmd = return_string((*param)->string); */
  if ((ret = gere_pos_history(buff, (*param)->pos_history,
			      nb_max_history(*history))) <= 0)
    {
      (*param)->pos_history = ret;
      free_string((*param)->string);
      (*param)->string = NULL;
      return ;
    }
  (*param)->pos_history = ret;
  free_string((*param)->string);
  (*param)->string = NULL;
  recup_new_string(param, return_pos_history(*history,
					     (*param)->pos_history));
  /* if (old_cmd != NULL) */
  /*   free(old_cmd); */
}
