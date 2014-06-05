#include "42sh.h"

void	parseur_history(char **cmd, t_history *history)
{
  char	*inter;

  if (my_strlen(*cmd) >= 2 && (*cmd)[0] == '!')
    {
      if ((*cmd)[1] == '!')
	inter = my_strdup(get_cmd_history(history,
					  nb_max_history(history) - 1));
      else
	inter = my_strdup(get_cmd_history(history, my_getnbr(&(*cmd)[1])));
      free(*cmd);
      *cmd = inter;
    }
}
