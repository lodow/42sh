/*
** history.c for history.c in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri Apr 12 19:14:58 2013 remi robert
** Last update Sun Apr 14 17:54:58 2013 remi robert
*/

#include "42sh.h"

int	load_history_f_file(char *line, t_sh *shell)
{
  add_history(&(shell->history), line);
  return (1);
}

int		view_history(char *path, char **argv, t_sh *shell)
{
  t_history	*pcourant;

  if (shell->history == NULL)
    return (-1);
  pcourant = shell->history;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  while (pcourant != NULL)
    {
      my_putstr(" ", 1, -1);
      my_put_nbr(pcourant->nb_history);
      my_putstr("  ", 1, -1);
      my_putstr(pcourant->cmd, 1, -1);
      my_putstr("\n", 1, -1);
      pcourant = pcourant->back;
    }
  return (0);
}

void	free_history(t_history *ptete)
{
  t_history	*pcourant;

  if (ptete == NULL)
    return ;
  pcourant = ptete;
  while (pcourant != NULL)
    {
      pcourant = pcourant->next;
      if (pcourant->back != NULL)
        {
          if (pcourant->back->cmd != NULL)
            free(pcourant->back->cmd);
          free(pcourant->back);
        }
    }
}

void		clear_history(t_history *ptr)
{
  if (ptr == NULL)
    return ;
  while (ptr->next != NULL)
    {
      ptr = ptr->next;
      if (ptr->back->cmd != NULL)
        free(ptr->back->cmd);
      free(ptr->back);
    }
  if (ptr->cmd != NULL)
    free(ptr->cmd);
  free(ptr);
}
