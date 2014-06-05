#include "42sh.h"

int	clear_scream(void)
{
  char	*s;

  if ((s = tgetstr("cl", NULL)) == NULL)
    {
      my_perror("tgetstr");
      return (EXIT_FAILURE);
    }
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}
