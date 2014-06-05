#include "42sh.h"

char	*my_tgetstr(char *cap)
{
  char	*s;

  if ((s = tgetstr(cap, NULL)) == NULL)
    {
      my_putstr("Error load capacity : ", 2, -1);
      my_putstr(cap, 2, -1);
      my_putstr("\n", 2, -1);
      return (NULL);
    }
  return (s);
}

void	init_capacity_termcap(t_termcap *termcap)
{
  termcap->str_cl = my_tgetstr("cl");
  termcap->str_do = my_tgetstr("do");
  termcap->str_up = my_tgetstr("up");
  termcap->str_le = my_tgetstr("le");
  termcap->str_ce = my_tgetstr("ce");
  termcap->str_cd = my_tgetstr("cd");
  termcap->str_ri = my_tgetstr("nd");
}
