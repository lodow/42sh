#include "42sh.h"

int	up_curser(void)
{
  char	*s;

  if ((s = tgetstr("up", NULL)) == NULL)
    {
      my_perror("tgetstr");
      return (EXIT_FAILURE);
    }
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}

int	do_curser(void)
{
  char	*s;

  if ((s = tgetstr("do", NULL)) == NULL)
    {
      my_perror("tgetstr");
      return (EXIT_FAILURE);
    }
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}

int	curseur(int x, int y)
{
  char	*s;
  char	*curser;

  if ((s = tgetstr("cm", NULL)) == NULL)
    {
      my_perror("tgetstr");
      return (EXIT_FAILURE);
    }
  if ((curser = tgoto(s, x, y)) == NULL)
    return (EXIT_FAILURE);
  my_putstr_termcap(-1, curser);
  return (EXIT_SUCCESS);
}
