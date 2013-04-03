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
  res->line = lign;
  tr_str(res->line, '\t', ' ');
  res->argv = str_to_wordtab(res->line, " ", 1);
  alias_replace(&(res->argv), shell->alias_tab);
  res->cmd_fpath = exec_full_path(res->argv[0], shell->path);
  // replace env var in argv here (using func check_vars_in_str)
  return (res);
}
