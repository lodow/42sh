/*
** parseur_history.c for parseur_history in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 24 09:54:35 2013 remi robert
** Last update Fri May 24 20:05:58 2013 remi robert
*/

#include "42sh.h"

char	*pars_history_option(char *str, t_history *history)
{
  char	**tab;
  char	*opt;
  char	*nline;

  if (((tab = str_to_wordtab(str, " ", 1)) == NULL) || (tab[0] == NULL))
    return (NULL);
  opt = tab[0];
  nline = str;
  if (!my_strncmp(opt, "!", -1))
    nline = history->cmd;
  free_ptr_tab((void**)tab, &free);
  return (nline);
}

void	parseur_history(char **cmd, t_history *history)
{
  char	*res;
  char	**tab;
  int	i;

  i = 0;
  if (((tab = str_to_wordtab((*cmd), "!", 1)) == NULL) || (history == NULL))
    return ;
  while (tab[i] != NULL)
    {
      res = pars_history_option(tab[i], history);
      if (tab[i] != res)
        free(tab[i]);
      tab[i] = res;
      i++;
    }
  res = strtab_to_str(tab, NULL);
  free_ptr_tab((void**)tab, &free);
  free(*cmd);
  (*cmd) = res;
}
