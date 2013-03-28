/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "history.h"

t_dlist	*init_hist()
{
  t_dlist	*hist;

  my_add_to_list(&hist, "");
  return (hist);
}

char	*hist_line(t_dlist *hist)
{
  return (hist->data);
}

t_dlist	*prev_hist(t_dlist *hist)
{
  t_dlist	*tmp;

  tmp = hist->prec;
  if (tmp == NULL)
    return (hist);
  else
    return (tmp);
}

t_dlist	*next_hist(t_dlist *hist)
{
  t_dlist	*tmp;

  tmp = hist->next;
  if (tmp == NULL)
    return (hist);
  else
    return (tmp);
}

void	add_to_history(t_dlist *hist, char *line)
{
  my_add_to_list(&hist, line);
}
