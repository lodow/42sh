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
  res->pid.pid = -1;
  res->return_value = 0;
  tr_str(res->line, '\t', ' ');
  res->line = check_vars_in_str(res->line, shell->env);
  res->argv = str_to_wordtab(res->line, " ", 1);
  rm_empty_str_f_tab(res->argv);
  alias_replace(&(res->argv), shell->alias_tab);
  res->cmd_fpath = exec_full_path(res->argv[0], shell->path);
  return (res);
}
