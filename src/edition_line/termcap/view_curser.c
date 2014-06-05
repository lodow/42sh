#include "42sh.h"

int	view_curser(void)
{
  char	*s;

  if ((s = tgetstr("ve", NULL)) == NULL)
    {
      my_perror("tgetstr");
      return (EXIT_FAILURE);
    }
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}

int	invisible_curseur(void)
{
  char	*s;

  if ((s = tgetstr("vi", NULL)) == NULL)
    {
      my_perror("tgetstr");
      return (EXIT_FAILURE);
    }
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}
