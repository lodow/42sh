#include "42sh.h"

int	verif_env(char **env)
{
  char	*term;

  if ((term = get_envvar("TERM", env)) == NULL)
    return (EXIT_FAILURE);
  if (tgetent(NULL, term) != 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
