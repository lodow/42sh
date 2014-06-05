#include "42sh.h"

char		*get_last_cmd_history(t_history *history,
				      char *cmd, int nb)
{
  t_history	*pcurrent;
  char		**tab;
  int		indice;

  if (history == NULL)
    return (NULL);
  pcurrent = history;
  indice = 0;
  while (pcurrent != NULL)
    {
      if ((tab = str_to_wordtab(pcurrent->cmd, " ", 0)) == NULL ||
	  tab[0] == NULL)
	return (NULL);
      if (str_cmp(tab[0], cmd) == 1)
	{
	  if (indice == nb)
	    return (pcurrent->cmd);
	  indice += 1;
	}
      free_ptr_tab((void *)tab, free);
      pcurrent = pcurrent->next;
    }
  return (NULL);
}

char		*get_cmd_history(t_history *history, int nb)
{
  t_history	*pcurrent;

  if (history == NULL)
    return (NULL);
  pcurrent = history;
  while (pcurrent != NULL)
    {
      if (nb == pcurrent->nb_history)
	return (pcurrent->cmd);
      pcurrent = pcurrent->next;
    }
  return (NULL);
}
