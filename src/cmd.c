/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "../include/42sh.h"

t_cmd	*create_n_cmd(t_sh *shell, char *lign)
{
  t_cmd	*res;

  if ((res = malloc(1 * sizeof(t_cmd))) == NULL)
    return (NULL);
  init_stdfd_t_def_val(&(res->fd), 0, 1, 2);
  res->line = lign;
  tr_str(res->line, '\t', ' ');
  res->argv = str_to_wordtab(res->line, " ", 1);
  return (NULL);
}
